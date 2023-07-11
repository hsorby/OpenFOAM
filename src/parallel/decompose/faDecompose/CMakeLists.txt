set(_FILES
  faFieldDecomposer.C
  faFieldDecomposerCache.C
  faMeshDecomposition.C
)
add_library(faDecompose ${_FILES})
target_compile_features(faDecompose PUBLIC cxx_std_11)
target_include_directories(faDecompose PUBLIC include PRIVATE includePrivate)
