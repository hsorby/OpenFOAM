set(_FILES
  solidParticle.C
  solidParticleIO.C
  solidParticleCloud.C
)
add_library(solidParticle ${_FILES})
target_compile_features(solidParticle PUBLIC cxx_std_11)
target_include_directories(solidParticle PUBLIC include PRIVATE includePrivate)
