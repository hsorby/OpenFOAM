set(_FILES
  scalarTransport/scalarTransport.C
  energyTransport/energyTransport.C
  electricPotential/electricPotential.C
)
add_library(solverFunctionObjects ${_FILES})
target_compile_features(solverFunctionObjects PUBLIC cxx_std_11)
target_include_directories(solverFunctionObjects PUBLIC include PRIVATE includePrivate)
target_link_libraries(solverFunctionObjects
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
