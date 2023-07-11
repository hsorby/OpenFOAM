set(_FILES
  Test-passiveParticle.C
)
add_executable(Test-passiveParticle ${_FILES})
target_compile_features(Test-passiveParticle PUBLIC cxx_std_11)
target_link_libraries(Test-passiveParticle PUBLIC finiteVolume)
