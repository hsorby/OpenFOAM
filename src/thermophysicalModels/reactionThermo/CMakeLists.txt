set(_FILES
  chemistryReaders/chemkinReader/chemkinReader.C
  chemistryReaders/chemistryReader/makeChemistryReaders.C
  mixtures/basicMultiComponentMixture/basicMultiComponentMixture.C
  mixtures/basicSpecieMixture/basicSpecieMixture.C
  mixtures/basicCombustionMixture/basicCombustionMixture.C
  psiReactionThermo/psiReactionThermo.C
  psiReactionThermo/psiReactionThermos.C
  psiuReactionThermo/psiuReactionThermo.C
  psiuReactionThermo/psiuReactionThermos.C
  rhoReactionThermo/rhoReactionThermo.C
  rhoReactionThermo/rhoReactionThermos.C
  derivedFvPatchFields/fixedUnburntEnthalpy/fixedUnburntEnthalpyFvPatchScalarField.C
  derivedFvPatchFields/gradientUnburntEnthalpy/gradientUnburntEnthalpyFvPatchScalarField.C
  derivedFvPatchFields/mixedUnburntEnthalpy/mixedUnburntEnthalpyFvPatchScalarField.C
  derivedFvPatchFields/speciesSorption/speciesSorptionFvPatchScalarField.C
  derivedFvPatchFields/enthalpySorption/enthalpySorptionFvPatchScalarField.C
  derivedFvPatchFields/boundarySourcePatch/boundarySourcePatch.C
  functionObjects/moleFractions/moleFractionsFunctionObjects.C
)
set(_INTERFACE_FILES ${CMAKE_CURRENT_BINARY_DIR}/chemkinLexer.C)
FLEX_TARGET(ChemistryScanner chemistryReaders/chemkinReader/chemkinLexer.L "${_INTERFACE_FILES}" COMPILE_FLAGS --c++)

add_library(reactionThermophysicalModels ${_FILES} ${_INTERFACE_FILES})
target_compile_features(reactionThermophysicalModels PUBLIC cxx_std_11)
target_include_directories(reactionThermophysicalModels
  PUBLIC
    include
    includePrivate
    chemistryReaders/chemistryReader
    chemistryReaders/foamChemistryReader
    functionObjects/moleFractions
    mixtures/SpecieMixture
    mixtures/egrMixture
    mixtures/homogeneousMixture
    mixtures/inhomogeneousMixture
    mixtures/multiComponentMixture
    mixtures/reactingMixture
    mixtures/singleComponentMixture
    mixtures/singleStepReactingMixture
    mixtures/veryInhomogeneousMixture
    psiuReactionThermo
)
target_link_libraries(reactionThermophysicalModels PUBLIC finiteVolume fluidThermophysicalModels solidSpecie)
