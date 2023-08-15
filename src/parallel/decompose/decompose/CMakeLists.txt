set(_FILES
  decompositionInformation.C
  decompositionModel.C
  dimFieldDecomposer.C
  fvFieldDecomposer.C
  fvFieldDecomposerCache.C
  pointFieldDecomposer.C
  pointFieldDecomposerCache.C
  lagrangianFieldDecomposer.C
  lagrangianFieldDecomposerCache.C
)
add_library(decompose ${_FILES})
target_compile_features(decompose PUBLIC cxx_std_11)
target_include_directories(decompose PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR} includePrivate)
target_link_libraries(decompose PUBLIC lagrangian meshTools finiteVolume dynamicMesh decompositionMethods)
