set(_FILES
  basicThermo/basicThermo.C
  fluidThermo/fluidThermo.C
  psiThermo/psiThermo.C
  psiThermo/psiThermos.C
  psiThermo/psiZoneThermos.C
  rhoThermo/rhoThermo.C
  rhoThermo/rhoThermos.C
  rhoThermo/liquidThermo.C
  rhoThermo/rhoZoneThermos.C
  derivedFvPatchFields/fixedEnergy/fixedEnergyFvPatchScalarField.C
  derivedFvPatchFields/gradientEnergy/gradientEnergyFvPatchScalarField.C
  derivedFvPatchFields/mixedEnergy/mixedEnergyFvPatchScalarField.C
  derivedFvPatchFields/energyJump/energyJump/energyJumpFvPatchScalarField.C
  derivedFvPatchFields/energyJump/energyJumpAMI/energyJumpAMIFvPatchScalarField.C
)
add_library(fluidThermophysicalModels ${_FILES})
target_compile_features(fluidThermophysicalModels PUBLIC cxx_std_11)
target_include_directories(fluidThermophysicalModels
  PUBLIC
    include
    includePrivate
    basicThermo
    heThermo
    mixtures/pureMixture
    mixtures/pureZoneMixture
    psiThermo
    rhoThermo
)
target_link_libraries(fluidThermophysicalModels PUBLIC finiteVolume compressibleTransportModels specie)
