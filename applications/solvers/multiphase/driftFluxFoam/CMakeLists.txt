set(_FILES
  incompressibleTwoPhaseInteractingMixture/incompressibleTwoPhaseInteractingMixture.C
  compressibleTurbulenceModels.C
  driftFluxFoam.C
)
add_executable(driftFluxFoam ${_FILES})
target_compile_features(driftFluxFoam PUBLIC cxx_std_11)
target_link_libraries(driftFluxFoam PUBLIC finiteVolume)
