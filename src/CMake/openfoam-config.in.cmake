@PACKAGE_INIT@

include(CMakeFindDependencyMacro)
list(APPEND CMAKE_MODULE_PATH @CMAKE_CURRENT_SOURCE_DIR@/cmakemodules)

find_dependency(ZLIB)
find_dependency(SCOTCH)
find_dependency(MPI)

include("${CMAKE_CURRENT_LIST_DIR}/openfoam-targets.cmake")

check_required_components(OpenFOAM)
