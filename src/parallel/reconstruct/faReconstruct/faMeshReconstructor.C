/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2021 OpenCFD Ltd.
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "faMeshReconstructor.H"
#include "globalIndex.H"
#include "globalMeshData.H"
#include "edgeHashes.H"
#include "Time.H"
#include "PstreamCombineReduceOps.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

int Foam::faMeshReconstructor::debug = 0;


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

void Foam::faMeshReconstructor::calcAddressing
(
    const labelUList& fvFaceProcAddr
)
{
    const globalIndex globalFaceNum(procMesh_.nFaces());

    // ----------------------
    // boundaryProcAddressing
    //
    // Trivial since non-processor boundary ordering is identical

    const label nPatches = procMesh_.boundary().size();

    faBoundaryProcAddr_ = identity(nPatches);

    // Mark processor patches
    for
    (
        label patchi = procMesh_.boundary().nNonProcessor();
        patchi < nPatches;
        ++patchi
    )
    {
        faBoundaryProcAddr_[patchi] = -1;
    }


    // ------------------
    // faceProcAddressing
    //
    // Transcribe/rewrite based on finiteVolume faceProcAddressing

    faFaceProcAddr_ = procMesh_.faceLabels();

    // From local faceLabels to proc values
    for (label& facei : faFaceProcAddr_)
    {
        // Use finiteVolume info, ignoring face flips
        facei = mag(fvFaceProcAddr[facei] - 1);
    }


    // Make global consistent.
    // Starting at '0', without gaps in numbering etc.
    // - the sorted order is the obvious solution
    {
        globalFaceNum.gather(faFaceProcAddr_, singlePatchFaceLabels_);

        labelList order(Foam::sortedOrder(singlePatchFaceLabels_));

        singlePatchFaceLabels_ = labelList(singlePatchFaceLabels_, order);

        globalFaceNum.scatter(order, faFaceProcAddr_);
    }

    // Broadcast the same information everywhere
    Pstream::scatter(singlePatchFaceLabels_);


    // ------------------
    // edgeProcAddressing
    //
    // This is more complicated.

    // Create a single (serial) patch of the finiteArea mesh without a
    // corresponding volume mesh, otherwise it would be the same as
    // reconstructPar on the volume mesh (big, slow, etc).
    //
    // Do manual point-merge and relabeling to avoid dependency on
    // finiteVolume pointProcAddressing

    faPointProcAddr_.clear();  // Final size == procMesh_.nPoints()

    // 1.
    // - Topological point merge of the area meshes
    // - use the local patch faces and points

    // 2.
    // - build a single (serial) patch of the finiteArea mesh only
    //   without any point support from the volume mesh
    // - it may be possible to skip this step, but not obvious how

    // The collected faces are contiguous per processor, which gives us
    // the possibility to easily identify their source by using the
    // global face indexing (if needed).
    // The ultimate face locations are handled with a separate ordering
    // list.

    const uindirectPrimitivePatch& procPatch = procMesh_.patch();


    {
        faceList singlePatchProcFaces;  // [proc0faces, proc1faces ...]
        labelList uniqueMeshPointLabels;

        // Local face points to compact merged point index
        labelList pointToGlobal;

        autoPtr<globalIndex> globalPointsPtr =
            procMesh_.mesh().globalData().mergePoints
            (
                procPatch.meshPoints(),
                procPatch.meshPointMap(),  // unused
                pointToGlobal,
                uniqueMeshPointLabels
            );

        // Gather faces, renumbered for the *merged* points
        faceList tmpFaces(globalFaceNum.localSize());

        forAll(tmpFaces, facei)
        {
            tmpFaces[facei] =
                face(pointToGlobal, procPatch.localFaces()[facei]);
        }

        globalFaceNum.gather
        (
            tmpFaces,
            singlePatchProcFaces,
            UPstream::msgType(),
            Pstream::commsTypes::scheduled
        );

        globalPointsPtr().gather
        (
            UIndirectList<point>
            (
                procPatch.points(),  // NB: mesh points (non-local)
                uniqueMeshPointLabels
            ),
            singlePatchPoints_
        );

        // Transcribe into final assembled order
        singlePatchFaces_.resize(singlePatchProcFaces.size());

        // Target face ordering
        labelList singlePatchProcAddr;
        globalFaceNum.gather(faFaceProcAddr_, singlePatchProcAddr);

        forAll(singlePatchProcAddr, facei)
        {
            const label targetFacei = singlePatchProcAddr[facei];
            singlePatchFaces_[targetFacei] = singlePatchProcFaces[facei];
        }

        // Use initial equivalent "global" (serial) patch
        // to establish the correct point and face walking order
        //
        // - only meaningful on master
        const primitivePatch initialPatch
        (
            SubList<face>(singlePatchFaces_),
            singlePatchPoints_
        );

        // Grab the faces/points in local point ordering
        tmpFaces = initialPatch.localFaces();
        pointField tmpPoints(initialPatch.localPoints());

        // The meshPointMap is contiguous, so flatten as linear list
        /// Map<label> mpm(initialPatch.meshPointMap());
        labelList mpm(initialPatch.nPoints());
        forAllConstIters(initialPatch.meshPointMap(), iter)
        {
            mpm[iter.key()] = iter.val();
        }
        Pstream::scatter(mpm);

        // Rewrite pointToGlobal according to the correct point order
        for (label& pointi : pointToGlobal)
        {
            pointi = mpm[pointi];
        }

        // Finalize. overwrite
        faPointProcAddr_ = std::move(pointToGlobal);

        singlePatchFaces_ = std::move(tmpFaces);
        singlePatchPoints_ = std::move(tmpPoints);
    }

    // Broadcast the same information everywhere
    Pstream::scatter(singlePatchFaces_);
    Pstream::scatter(singlePatchPoints_);

    // Now have enough global information to determine global edge mappings

    // Equivalent "global" (serial) patch
    const primitivePatch onePatch
    (
        SubList<face>(singlePatchFaces_),
        singlePatchPoints_
    );

    faEdgeProcAddr_.clear();
    faEdgeProcAddr_.resize(procMesh_.nEdges(), -1);

    {
        EdgeMap<label> globalEdgeMapping(2*onePatch.nEdges());

        // Pass 1: edge-hash lookup with edges in "natural" patch order

        // Can use local edges() directly without remap via meshPoints()
        // since the previous sorting means that we are already working
        // with faces that are in the local point order and even
        // the points themselves are also in the local point order
        for (const edge& e : onePatch.edges())
        {
            globalEdgeMapping.insert(e, globalEdgeMapping.size());
        }

        // Lookup proc local edges (in natural order) to global equivalent
        for (label edgei = 0; edgei < procPatch.nEdges(); ++edgei)
        {
            const edge globalEdge(faPointProcAddr_, procPatch.edges()[edgei]);

            const auto fnd = globalEdgeMapping.cfind(globalEdge);

            if (fnd.found())
            {
                faEdgeProcAddr_[edgei] = fnd.val();
            }
            else
            {
                FatalErrorInFunction
                    << "Failed to find edge " << globalEdge
                    << " this indicates a programming error" << nl
                    << exit(FatalError);
            }
        }
    }

    // Now have consistent global edge
    // This of course would all be too easy.
    // The finiteArea edge lists have been defined as their own sorted
    // order with sublists etc.

    // Gather edge ids for nonProcessor boundaries.
    // These will also be in the serial geometry

    Map<label> remapGlobal(2*onePatch.nEdges());
    for (label edgei = 0; edgei < onePatch.nInternalEdges(); ++edgei)
    {
        remapGlobal.insert(edgei, remapGlobal.size());
    }

    //
    singlePatchEdgeLabels_.clear();
    singlePatchEdgeLabels_.resize(procMesh_.boundary().nNonProcessor());

    forAll(singlePatchEdgeLabels_, patchi)
    {
        const faPatch& fap = procMesh_.boundary()[patchi];

        labelList& patchEdgeLabels = singlePatchEdgeLabels_[patchi];
        patchEdgeLabels = fap.edgeLabels();

        // Renumber from local edges to global edges (natural order)
        for (label& edgeId : patchEdgeLabels)
        {
            edgeId = faEdgeProcAddr_[edgeId];
        }

        // OR patchEdgeLabels =
        // UIndirectList<label>(faEdgeProcAddr_, fap.edgeLabels());


        // Collect from all processors
        combineReduce
        (
            patchEdgeLabels,
            ListOps::appendEqOp<label>()
        );

        // Sorted order will be the original non-decomposed order
        Foam::sort(patchEdgeLabels);

        for (const label sortedEdgei : patchEdgeLabels)
        {
            remapGlobal.insert(sortedEdgei, remapGlobal.size());
        }
    }

    {
        // Use the map to rewrite the local faEdgeProcAddr_

        labelList newEdgeProcAddr(faEdgeProcAddr_);

        label edgei = procMesh_.nInternalEdges();

        for (const faPatch& fap : procMesh_.boundary())
        {
            for (const label patchEdgei : fap.edgeLabels())
            {
                const label globalEdgei = faEdgeProcAddr_[patchEdgei];

                const auto fnd = remapGlobal.cfind(globalEdgei);
                if (fnd.found())
                {
                    newEdgeProcAddr[edgei] = fnd.val();
                    ++edgei;
                }
                else
                {
                    FatalErrorInFunction
                        << "Failed to find edge " << globalEdgei
                        << " this indicates a programming error" << nl
                        << exit(FatalError);
                }
            }
        }

        faEdgeProcAddr_ = std::move(newEdgeProcAddr);
    }
}


void Foam::faMeshReconstructor::initPatch() const
{
    serialPatchPtr_.reset
    (
        new primitivePatch
        (
            SubList<face>(singlePatchFaces_),
            singlePatchPoints_
        )
    );
}


void Foam::faMeshReconstructor::createMesh()
{
    const Time& runTime = procMesh_.mesh().time();

    // Time for non-parallel case (w/o functionObjects or libs)
    serialRunTime_ = Time::New(runTime.globalPath().toAbsolute());


    // Trivial polyMesh only containing points and faces.
    // This is valid, provided we don't use it for anything complicated.

    serialVolMesh_.reset
    (
        new polyMesh
        (
            IOobject
            (
                procMesh_.mesh().name(),  // Volume region name
                procMesh_.mesh().facesInstance(),

                *serialRunTime_,

                IOobject::NO_READ,
                IOobject::NO_WRITE,
                false  // not registered
            ),
            pointField(singlePatchPoints_),  // copy
            faceList(singlePatchFaces_),     // copy
            labelList(singlePatchFaces_.size(), Zero),  // faceOwner
            labelList(),  // faceNeighbour
            false  // no syncPar!
        )
    );

    // A simple area-mesh with one-to-one mapping of faceLabels
    serialAreaMesh_.reset
    (
        new faMesh
        (
            *serialVolMesh_,
            identity(singlePatchFaces_.size())  // faceLabels
        )
    );

    auto& completeMesh = *serialAreaMesh_;

    // Add in non-processor boundary patches
    PtrList<faPatch> completePatches(singlePatchEdgeLabels_.size());
    forAll(completePatches, patchi)
    {
        const labelList& patchEdgeLabels = singlePatchEdgeLabels_[patchi];

        const faPatch& fap = procMesh_.boundary()[patchi];

        const label neiPolyPatchId = fap.ngbPolyPatchIndex();

        completePatches.set
        (
            patchi,
            fap.clone
            (
                completeMesh.boundary(),
                patchEdgeLabels,
                patchi,  // index
                neiPolyPatchId
            )
        );
    }

    completeMesh.addFaPatches(completePatches);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::faMeshReconstructor::faMeshReconstructor
(
    const faMesh& procMesh
)
:
    procMesh_(procMesh)
{
    if (!Pstream::parRun())
    {
        FatalErrorInFunction
            << "Can only be called in parallel!!" << nl
            << exit(FatalError);
    }

    // Require faceProcAddressing from finiteVolume decomposition
    labelIOList fvFaceProcAddressing
    (
        IOobject
        (
            "faceProcAddressing",
            procMesh_.mesh().facesInstance(),

            // Or search?
            // procMesh_.time().findInstance
            // (
            //     // Search for polyMesh face instance
            //     // mesh.facesInstance()
            //     procMesh_.mesh().meshDir(),
            //     "faceProcAddressing"
            // ),

            polyMesh::meshSubDir,
            procMesh_.mesh(),    // The polyMesh db
            IOobject::MUST_READ,
            IOobject::NO_WRITE,
            false  // not registered
        )
    );

    calcAddressing(fvFaceProcAddressing);
}


Foam::faMeshReconstructor::faMeshReconstructor
(
    const faMesh& procMesh,
    const labelUList& fvFaceProcAddressing
)
:
    procMesh_(procMesh)
{
    if (!Pstream::parRun())
    {
        FatalErrorInFunction
            << "Can only be called in parallel!!" << nl
            << exit(FatalError);
    }

    calcAddressing(fvFaceProcAddressing);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::faMeshReconstructor::~faMeshReconstructor()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::faMeshReconstructor::clearGeom()
{
    serialAreaMesh_.reset(nullptr);
    serialVolMesh_.reset(nullptr);
    serialRunTime_.reset(nullptr);
}


const Foam::primitivePatch& Foam::faMeshReconstructor::patch() const
{
    if (!serialPatchPtr_)
    {
        initPatch();
    }

    return *serialPatchPtr_;
}


Foam::primitivePatch& Foam::faMeshReconstructor::patch()
{
    if (!serialPatchPtr_)
    {
        initPatch();
    }

    return *serialPatchPtr_;
}


const Foam::faMesh& Foam::faMeshReconstructor::mesh() const
{
    if (!serialAreaMesh_)
    {
        const_cast<faMeshReconstructor&>(*this).createMesh();
    }

    return *serialAreaMesh_;
}


void Foam::faMeshReconstructor::writeAddressing() const
{
    writeAddressing(procMesh_.mesh().facesInstance());
}


void Foam::faMeshReconstructor::writeAddressing(const word& timeName) const
{
    // Write copies

    IOobject ioAddr
    (
        "procAddressing",
        timeName,
        faMesh::meshSubDir,
        procMesh_.mesh(),  // The polyMesh
        IOobject::NO_READ,
        IOobject::NO_WRITE,
        false  // not registered
    );

    // boundaryProcAddressing
    ioAddr.rename("boundaryProcAddressing");
    labelIOList(ioAddr, faBoundaryProcAddr_).write();

    // faceProcAddressing
    ioAddr.rename("faceProcAddressing");
    labelIOList(ioAddr, faFaceProcAddr_).write();

    // pointProcAddressing
    ioAddr.rename("pointProcAddressing");
    labelIOList(ioAddr, faPointProcAddr_).write();

    // edgeProcAddressing
    ioAddr.rename("edgeProcAddressing");
    labelIOList(ioAddr, faEdgeProcAddr_).write();
}


void Foam::faMeshReconstructor::writeMesh() const
{
    writeMesh(procMesh_.mesh().facesInstance());
}


void Foam::faMeshReconstructor::writeMesh(const word& timeName) const
{
    const faMesh& fullMesh = this->mesh();

    const bool oldDistributed = fileHandler().distributed();
    auto oldHandler = fileHandler(fileOperation::NewUncollated());
    fileHandler().distributed(true);

    if (Pstream::master())
    {
        const bool oldParRun = Pstream::parRun(false);

        IOobject io(fullMesh.boundary());

        io.rename("faceLabels");
        labelIOList(io, singlePatchFaceLabels_).write();

        fullMesh.boundary().write();

        Pstream::parRun(oldParRun);
    }

    // Restore old settings
    if (oldHandler)
    {
        fileHandler(std::move(oldHandler));
    }
    fileHandler().distributed(oldDistributed);
}


// ************************************************************************* //