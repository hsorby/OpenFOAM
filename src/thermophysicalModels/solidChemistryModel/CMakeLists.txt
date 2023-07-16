set(_FILES
  basicSolidChemistryModel/basicSolidChemistryModel.C
  basicSolidChemistryModel/basicSolidChemistryModelNew.C
  basicSolidChemistryModel/basicSolidChemistryModels.C
  solidChemistrySolver/makeSolidChemistrySolvers.C
)
add_library(solidChemistryModel ${_FILES})
target_compile_features(solidChemistryModel PUBLIC cxx_std_11)
target_include_directories(solidChemistryModel
  PUBLIC
    include
    includePrivate
    pyrolysisChemistryModel
    solidChemistryModel
)
target_link_libraries(solidChemistryModel PUBLIC finiteVolume chemistryModel solidThermo)
