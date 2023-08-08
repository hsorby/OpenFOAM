set(_FILES
  PstreamGlobals.C
  UPstream.C
  UPstreamAllToAll.C
  UPstreamBroadcast.C
  UPstreamGatherScatter.C
  UPstreamReduce.C
  UPstreamRequest.C
  UIPstreamRead.C
  UOPstreamWrite.C
  UIPBstreamRead.C
  UOPBstreamWrite.C
)
add_library(Pstream ${_FILES})
target_compile_features(Pstream PUBLIC cxx_std_11)
target_include_directories(Pstream
  PRIVATE
    includePrivate
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OPENFOAM_SRC_DIR}/OpenFOAM/includePrivate
    ${OPENFOAM_SRC_DIR}/OpenFOAM/primitives/strings/string
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/LinkedLists/accessTypes/UILList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/Lists/List
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/HashTables/HashTable
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/HashTables/HashPtrTable
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/LinkedLists/accessTypes/LList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/Lists/FixedList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/PtrLists/PtrListDetail
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/PtrLists/UPtrList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/PtrLists/PtrList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/LinkedLists/accessTypes/LPtrList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/Lists/DynamicList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/primitives/enums
    ${OPENFOAM_SRC_DIR}/OpenFOAM/primitives/strings/lists
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/LinkedLists/accessTypes/ILList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/db/dictionary
    ${OPENFOAM_SRC_DIR}/OpenFOAM/db/dictionary/primitiveEntry
    ${OPENFOAM_SRC_DIR}/OpenFOAM/global/fileOperations/masterUncollatedFileOperation
    ${OPENFOAM_SRC_DIR}/OpenFOAM/primitives/strings/stringOps
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/IndirectLists/IndirectListBase
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/HashTables/HashSet
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/Bits/PackedList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/db/IOobject
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/Bits/bitSet
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/Lists/ListOps
    ${OPENFOAM_SRC_DIR}/OpenFOAM/db/IOstreams/Pstreams
    ${OPENFOAM_SRC_DIR}/OpenFOAM/db/objectRegistry
    ${OPENFOAM_SRC_DIR}/OpenFOAM/primitives/VectorSpace
    ${OPENFOAM_SRC_DIR}/OpenFOAM/fields/Fields/Field
    ${OPENFOAM_SRC_DIR}/OpenFOAM/meshes/polyMesh/mapPolyMesh/mapDistribute
    ${OPENFOAM_SRC_DIR}/OpenFOAM/matrices/MatrixBlock
    ${OPENFOAM_SRC_DIR}/OpenFOAM/matrices/Matrix
    ${OPENFOAM_SRC_DIR}/OpenFOAM/matrices/SquareMatrix
    ${OPENFOAM_SRC_DIR}/OpenFOAM/matrices/SymmetricSquareMatrix
    ${OPENFOAM_SRC_DIR}/OpenFOAM/matrices/DiagonalMatrix
    ${OPENFOAM_SRC_DIR}/OpenFOAM/matrices/scalarMatrices
    ${OPENFOAM_SRC_DIR}/OpenFOAM/dimensionedTypes/dimensionedType
    ${OPENFOAM_SRC_DIR}/OpenFOAM/db/dynamicLibrary/dlLibraryTable
    ${OPENFOAM_SRC_DIR}/OpenFOAM/db/functionObjects/functionObjectProperties
)
target_link_libraries(Pstream PUBLIC OSspecific MPI::MPI_CXX)
target_compile_definitions(Pstream PRIVATE WM_LABEL_SIZE=${WM_LABEL_SIZE} WM_${WM_PRECISION} NoRepository OPENFOAM=2306)
if (BUILD_SHARED_LIBS)
  target_link_options(Pstream PUBLIC -undefined dynamic_lookup)
endif()
install(TARGETS Pstream DESTINATION ${CMAKE_INSTALL_LIBDIR}/openfoam EXPORT openfoam-targets)
