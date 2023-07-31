set(_FILES
  hydrostaticPressure/hydrostaticPressure.C
)
add_library(initialisationFunctionObjects ${_FILES})
target_compile_features(initialisationFunctionObjects PUBLIC cxx_std_11)
target_include_directories(initialisationFunctionObjects PUBLIC include PRIVATE includePrivate)
target_link_libraries(initialisationFunctionObjects
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
