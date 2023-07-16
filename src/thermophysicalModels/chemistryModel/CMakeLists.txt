set(_FILES
  chemistryModel/basicChemistryModelCamel/basicChemistryModel.C
  chemistryModel/BasicChemistryModel/BasicChemistryModels.C
  chemistryModel/TDACChemistryModel/reduction/makeChemistryReductionMethods.C
  chemistryModel/TDACChemistryModel/tabulation/makeChemistryTabulationMethods.C
  chemistrySolver/chemistrySolver/makeChemistrySolvers.C
  functionObjects/specieReactionRates/specieReactionRates.C
  functionObjects/BilgerMixtureFraction/BilgerMixtureFraction.C
)
add_library(chemistryModel ${_FILES})
target_compile_features(chemistryModel PUBLIC cxx_std_11)
target_include_directories(chemistryModel
  PUBLIC
    include
    includePrivate
    chemistryModel/BasicChemistryModel
    chemistryModel/StandardChemistryModel
    chemistryModel/TDACChemistryModel
    chemistryModel/TDACChemistryModel/reduction/DAC
    chemistryModel/TDACChemistryModel/reduction/DRG
    chemistryModel/TDACChemistryModel/reduction/DRGEP
    chemistryModel/TDACChemistryModel/reduction/EFA
    chemistryModel/TDACChemistryModel/reduction/PFA
    chemistryModel/TDACChemistryModel/reduction/chemistryReductionMethod
    chemistryModel/TDACChemistryModel/reduction/noChemistryReduction
    chemistryModel/TDACChemistryModel/tabulation/ISAT
    chemistryModel/TDACChemistryModel/tabulation/ISAT/binaryNode
    chemistryModel/TDACChemistryModel/tabulation/ISAT/binaryTree
    chemistryModel/TDACChemistryModel/tabulation/ISAT/chemPointISAT
    chemistryModel/TDACChemistryModel/tabulation/chemistryTabulationMethod
    chemistryModel/TDACChemistryModel/tabulation/noChemistryTabulation
    chemistrySolver/EulerImplicit
    chemistrySolver/chemistrySolver
    chemistrySolver/noChemistrySolver
    chemistrySolver/ode
)
target_link_libraries(chemistryModel PUBLIC finiteVolume fluidThermophysicalModels reactionThermophysicalModels ODE)
