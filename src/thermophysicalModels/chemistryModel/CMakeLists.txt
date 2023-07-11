set(_FILES
  chemistryModel/basicChemistryModel/basicChemistryModel.C
  chemistryModel/BasicChemistryModel/BasicChemistryModels.C
  chemistryModel/TDACChemistryModel/reduction/makeChemistryReductionMethods.C
  chemistryModel/TDACChemistryModel/tabulation/makeChemistryTabulationMethods.C
  chemistrySolver/chemistrySolver/makeChemistrySolvers.C
  functionObjects/specieReactionRates/specieReactionRates.C
  functionObjects/BilgerMixtureFraction/BilgerMixtureFraction.C
)
add_library(chemistryModel ${_FILES})
target_compile_features(chemistryModel PUBLIC cxx_std_11)
target_include_directories(chemistryModel PUBLIC include PRIVATE includePrivate)
