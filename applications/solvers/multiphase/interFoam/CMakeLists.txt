set(_FILES
  interFoam.C
)
add_executable(interFoam ${_FILES})
target_include_directories(interFoam PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../VoF)
target_compile_features(interFoam PUBLIC cxx_std_11)
target_link_libraries(interFoam PUBLIC
  finiteVolume
  fvOptions
  meshTools
  sampling
  dynamicFvMesh
  incompressibleTransportModels
  interfaceProperties
  immiscibleIncompressibleTwoPhaseMixture
  twoPhaseProperties
  turbulenceModels
  incompressibleTurbulenceModels
  waveModels
  VoFphaseTurbulentTransportModels
  incompressibleInterPhaseTransportModels
)
