/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2016-2017 Wikki Ltd
    Copyright (C) 2018-2023 OpenCFD Ltd.
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

Class
    Foam::faBoundaryMesh

Description
    Finite area boundary mesh

SourceFiles
    faBoundaryMesh.C

Author
    Zeljko Tukovic, FMENA
    Hrvoje Jasak, Wikki Ltd.

\*---------------------------------------------------------------------------*/

#ifndef Foam_faBoundaryMesh_H
#define Foam_faBoundaryMesh_H

#include "regIOobject.H"
#include "faPatch.H"
#include "labelPair.H"
#include "lduInterfacePtrsList.H"
#include "wordList.H"
#include "pointField.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward Declarations
class faMesh;
class faBoundaryMesh;
class wordRes;

Ostream& operator<<(Ostream&, const faBoundaryMesh&);

/*---------------------------------------------------------------------------*\
                      Class faBoundaryMesh Declaration
\*---------------------------------------------------------------------------*/

class faBoundaryMesh
:
    public faPatchList,
    public regIOobject
{
    // Private Data

        //- Reference to mesh
        const faMesh& mesh_;

        //- Demand-driven: list of patch ids per group
        mutable autoPtr<HashTable<labelList>> groupIDsPtr_;


    // Private Member Functions

        //- Some patches have inGroup entries
        bool hasGroupIDs() const;

        //- Calculate group name to patch ids lookup
        void calcGroupIDs() const;

        //- Read if IOobject flags set. Return true if read.
        bool readContents(const bool allowReadIfPresent);


public:

    //- Runtime type information
    TypeName("faBoundaryMesh");


    // Generated Methods

        //- No copy construct
        faBoundaryMesh(const faBoundaryMesh&) = delete;

        //- No copy assignment
        void operator=(const faBoundaryMesh&) = delete;


    // Constructors

        //- Construct from faMesh
        faBoundaryMesh
        (
            const IOobject& io,
            const faMesh& fam
        );

        //- Construct from faMesh and given size
        faBoundaryMesh
        (
            const IOobject& io,
            const faMesh& fam,
            const label size
        );


    //- Destructor
    ~faBoundaryMesh() = default;


    // Member Functions

        //- Clear the patch list and all demand-driven data
        void clear();

        //- Return the mesh reference
        const faMesh& mesh() const noexcept
        {
            return mesh_;
        }

        //- Return a list of edgeLabels for each patch
        UPtrList<const labelUList> edgeLabels() const;

        //- Return a list of edgeFaces for each patch
        UPtrList<const labelUList> edgeFaces() const;

        //- Return a list of pointers for each patch
        //- with only those pointing to interfaces being set
        lduInterfacePtrsList interfaces() const;

        //- The number of patches before the first processor patch.
        label nNonProcessor() const;

        //- The number of processorFaPatch patches
        label nProcessorPatches() const;

        //- Return a list of patch names
        wordList names() const;

        //- Return a list of patch types
        wordList types() const;

        //- Return a list of patch start indices
        labelList patchStarts() const;

        //- Return a list of patch sizes (number of edges in each patch)
        labelList patchSizes() const;

        //- Return a list of patch ranges
        List<labelRange> patchRanges() const;

        //- A list of the group names (if any)
        wordList groupNames() const;

        //- The start label of the edges in the faMesh edges list
        //  Same as mesh.nInternalEdges()
        label start() const;

        //- The number of boundary edges for the underlying mesh
        //  Same as mesh.nBoundaryEdges()
        label nEdges() const;

        //- The edge range for all boundary edges
        //  Spans [nInternalEdges, nEdges) of the underlying mesh
        labelRange range() const;


        //- Return (sorted) patch indices for all matches.
        //  Optionally matches patch groups.
        //  A no-op (returns empty list) for an empty matcher
        labelList indices
        (
            const wordRe& matcher,
            const bool useGroups = true
        ) const;

        //- Return (sorted) patch indices for all matches.
        //  Optionally matches patch groups.
        //  A no-op (returns empty list) for an empty matcher
        labelList indices
        (
            const wordRes& matcher,
            const bool useGroups = true
        ) const;

        //- Return patch index for the first match, return -1 if not found
        //  A no-op (returns -1) for an empty key
        label findIndex(const wordRe& key) const;

        //- Find patch index given a name, return -1 if not found
        //  A no-op (returns -1) for an empty name
        label findPatchID
        (
            const word& patchName,
            const bool allowNotFound = true
        ) const;

        //- Return patch index for a given edge label
        label whichPatch(const label edgeIndex) const;

        //- The patch indices per patch group
        const HashTable<labelList>& groupPatchIDs() const;

        //- Set/add group with patches
        void setGroup(const word& groupName, const labelUList& patchIDs);

        //- Check boundary definition
        //  \return True if in error.
        bool checkDefinition(const bool report = false) const;

        //- Check whether all procs have all patches and in same order.
        //  \return True if in error.
        bool checkParallelSync(const bool report = false) const;


    // Edit

        //- Calculate the geometry for the patches
        //  (transformation tensors etc.)
        void calcGeometry();

        //- Correct faBoundaryMesh after moving points
        void movePoints(const pointField&);

        //- Correct faBoundaryMesh after topology update
        void updateMesh();

        //- The writeData member function required by regIOobject
        bool writeData(Ostream& os) const;

        //- Write using stream options
        virtual bool writeObject
        (
            IOstreamOption streamOpt,
            const bool writeOnProc
        ) const;


    // Ostream Operator

        friend Ostream& operator<<(Ostream&, const faBoundaryMesh&);


    // Housekeeping

        //- Identical to the indices() method (AUG-2018)
        FOAM_DEPRECATED_FOR(2018-08, "indices() method")
        labelList findIndices(const wordRe& key, bool useGroups=true) const
        {
            return indices(key, useGroups);
        }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
