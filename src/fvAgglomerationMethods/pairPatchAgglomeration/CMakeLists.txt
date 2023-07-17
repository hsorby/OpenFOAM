set(_FILES
  pairPatchAgglomeration.C
)
add_library(pairPatchAgglomeration ${_FILES})
target_compile_features(pairPatchAgglomeration PUBLIC cxx_std_11)
target_include_directories(pairPatchAgglomeration PUBLIC include includePrivate ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pairPatchAgglomeration PUBLIC finiteVolume)
