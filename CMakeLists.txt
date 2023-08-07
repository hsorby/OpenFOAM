
cmake_minimum_required(VERSION 3.18.0)

set(CMAKE_OSX_DEPLOYMENT_TARGET 13 CACHE STRING "Minimum OS X deployment version.")

set(PROJECT_NAME OpenFOAM)
set(_PROJECT_VERSION 10.0.0)
set(PROJECT_DEVELOPER_VERSION )
project(${PROJECT_NAME} VERSION ${_PROJECT_VERSION} LANGUAGES CXX C)

include(GNUInstallDirs)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmakemodules)

option(OPENFOAM_SHARED_LIBS "Build shared libraries" ON)
set(BUILD_SHARED_LIBS ${OPENFOAM_SHARED_LIBS})

set(CMAKE_CXX_STANDARD 14)
set(WM_LABEL_SIZE 32)
set(WM_PRECISION DP)

add_compile_definitions(NoRepository OPENFOAM=2306)

find_package(SCOTCH REQUIRED)
find_package(ZLIB REQUIRED)
find_package(FLEX REQUIRED)
find_package(RAGEL REQUIRED)
find_package(FFTW REQUIRED)
find_package(MPI)

if (MPI_FOUND)
  set(MPI_OPTION OpenMPI)
else()
  set(MPI_OPTION DummyMPI)
endif()

add_subdirectory(cmakemodules/lemon)

include(GenerateLemon)

set (CMAKE_CXX_FLAGS "-ftemplate-depth-100 -Wall -Wextra -Wold-style-cast -Wnon-virtual-dtor -Wno-unused-parameter -Wno-invalid-offsetof -Wno-undefined-var-template -Wno-old-style-cast")

set(BUILD git-repo)
set(PATCH 1)
set(VERSION ${_PROJECT_VERSION})

add_subdirectory(src)

add_subdirectory(applications)

export(EXPORT openfoam-targets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/openfoam-targets.cmake"
       NAMESPACE OpenFOAM::
)

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/src/CMake/openfoam-config.in.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/openfoam-config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/OpenFOAM
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/openfoam-config-version.cmake"
  VERSION "${_PROJECT_VERSION}"
  COMPATIBILITY AnyNewerVersion
)

message("export WM_OPTIONS=${CMAKE_CXX_PLATFORM_ID}${CMAKE_CXX_COMPILER_ID}${WM_PRECISION}${WM_LABEL_SIZE}${MPI_OPTION}${CMAKE_BUILD_TYPE}")
message("export WM_BUILD_DIR=${CMAKE_CURRENT_BINARY_DIR}")
