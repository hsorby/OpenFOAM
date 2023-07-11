set(_FILES
  particle/particle.C
  particle/particleIO.C
  passiveParticle/passiveParticleCloud.C
  indexedParticle/indexedParticleCloud.C
  injectedParticle/injectedParticle.C
  injectedParticle/injectedParticleIO.C
  injectedParticle/injectedParticleCloud.C
  InteractionLists/referredWallFace/referredWallFace.C
)
add_library(lagrangian ${_FILES})
target_compile_features(lagrangian PUBLIC cxx_std_11)
target_include_directories(lagrangian PUBLIC include PRIVATE includePrivate)
