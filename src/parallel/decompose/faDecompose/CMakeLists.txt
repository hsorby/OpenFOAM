set(_FILES
  faFieldDecomposer.C
  faFieldDecomposerCache.C
  faMeshDecomposition.C
)
add_library(faDecompose ${_FILES})
target_compile_features(faDecompose PUBLIC cxx_std_11)
target_include_directories(faDecompose PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR} PRIVATE includePrivate)
target_link_libraries(faDecompose PUBLIC meshTools finiteVolume dynamicMesh finiteArea decompositionMethods)
