set(_FILES
  processorMeshes.C
  fvFieldReconstructor.C
  pointFieldReconstructor.C
  passivePositionParticleCloud.C
  lagrangianReconstructor.C
)
add_library(reconstruct ${_FILES})
target_compile_features(reconstruct PUBLIC cxx_std_11)
target_include_directories(reconstruct PUBLIC include PRIVATE includePrivate)
