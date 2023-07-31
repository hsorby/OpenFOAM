set(_FILES
  sizeDistribution/sizeDistribution.C
  phaseForces/phaseForces.C
)
add_library(phaseFunctionObjects ${_FILES})
target_compile_features(phaseFunctionObjects PUBLIC cxx_std_11)
target_include_directories(phaseFunctionObjects PUBLIC include PRIVATE includePrivate)
target_link_libraries(phaseFunctionObjects
  PUBLIC
    sampling
    lagrangian
    distributionModels
    fluidThermophysicalModels
    solidThermo
    incompressibleTransportModels
    turbulenceModels
    compressibleTransportModels
    incompressibleTurbulenceModels
    compressibleTurbulenceModels
    turbulenceModelSchemes
    chemistryModel
    reactionThermophysicalModels
    pairPatchAgglomeration
    incompressibleMultiphaseSystems
    reactingMultiphaseSystem
)
