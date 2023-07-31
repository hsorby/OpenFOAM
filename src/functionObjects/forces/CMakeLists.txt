set(_FILES
  forces/forces.C
  forceCoeffs/forceCoeffs.C
  propellerInfo/propellerInfo.C
)
add_library(forces ${_FILES})
target_compile_features(forces PUBLIC cxx_std_11)
target_include_directories(forces PUBLIC include PRIVATE includePrivate)
target_link_libraries(forces
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
