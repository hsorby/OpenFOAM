

cmake_minimum_required(VERSION 3.18.0)

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.14 CACHE STRING "Minimum OS X deployment version.")

set(PROJECT_NAME OpenFOAM)
set(_PROJECT_VERSION 10.0.0)
set(PROJECT_DEVELOPER_VERSION )
project(${PROJECT_NAME} VERSION ${_PROJECT_VERSION} LANGUAGES CXX C)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmakemodules)

include(CheckIncludeFileCXX)
check_include_file_cxx("mach-o/dyld.h" HAVE_MACH0_DYLD_H)

set(CMAKE_CXX_STANDARD 14)
add_compile_definitions(WM_LABEL_SIZE=32 WM_DP NoRepository)
if (HAVE_MACH0_DYLD_H)
  add_compile_definitions(HAVE_MACH0_DYLD_H)
endif()

find_package(SCOTCH REQUIRED)
find_package(ZLIB REQUIRED)
find_package(FLEX REQUIRED)

set (CMAKE_CXX_FLAGS "-ftemplate-depth-100 -Wall -Wextra -Wold-style-cast -Wnon-virtual-dtor -Wno-unused-parameter -Wno-invalid-offsetof -Wno-undefined-var-template -Wno-old-style-cast")

add_subdirectory(src)

add_subdirectory(applications)
