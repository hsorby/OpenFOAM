set(_FILES
  POSIX.C
  cpuInfo/cpuInfo.C
  cpuTime/cpuTimePosix.C
  memInfo/memInfo.C
  signals/sigFpe.C
  signals/sigSegv.C
  signals/sigInt.C
  signals/sigQuit.C
  signals/sigStopAtWriteNow.C
  signals/sigWriteNow.C
  signals/timer.C
  regExp/regExpPosix.C
  fileStat/fileStat.C
  fileMonitor/fileMonitor.C
)
if (CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "Sun64")
  list(APPEND _FILES printStack/dummyPrintStack.C)
else()
  list(APPEND _FILES printStack/printStack.C)
endif()

add_library(OSspecific ${_FILES})
target_compile_features(OSspecific PUBLIC cxx_std_11)
target_include_directories(OSspecific
  PUBLIC
    includePrivate
  PRIVATE
    ${OPENFOAM_SRC_DIR}/OpenFOAM/includePrivate
    ${OPENFOAM_SRC_DIR}/OpenFOAM/primitives/strings/string
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/HashTables/HashTable
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/LinkedLists/accessTypes/UILList
    ${OPENFOAM_SRC_DIR}/OpenFOAM/containers/Lists/List
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
#target_link_libraries(OSspecific PUBLIC OpenFOAM)
target_compile_definitions(OSspecific PRIVATE WM_LABEL_SIZE=${WM_LABEL_SIZE} WM_${WM_PRECISION} NoRepository OPENFOAM=2306)
if (BUILD_SHARED_LIBS)
  target_link_options(OSspecific PUBLIC -undefined dynamic_lookup)
endif()
install(TARGETS OSspecific DESTINATION ${CMAKE_INSTALL_LIBDIR}/openfoam EXPORT openfoam-targets)
