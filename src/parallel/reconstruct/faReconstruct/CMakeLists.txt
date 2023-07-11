set(_FILES
  processorFaMeshes.C
  faFieldReconstructor.C
  faMeshReconstructor.C
)
add_library(faReconstruct ${_FILES})
target_compile_features(faReconstruct PUBLIC cxx_std_11)
target_include_directories(faReconstruct PUBLIC include PRIVATE includePrivate)
