set(_FILES
  pyrolysisModel/pyrolysisModel.C
  pyrolysisModel/pyrolysisModelNew.C
  reactingOneDim/reactingOneDim.C
  noPyrolysis/noPyrolysis.C
  thermo/thermo.C
  pyrolysisModel/pyrolysisModelCollection.C
)
add_library(pyrolysisModels ${_FILES})
target_compile_features(pyrolysisModels PUBLIC cxx_std_11)
target_include_directories(pyrolysisModels PUBLIC include includePrivate)
target_link_libraries(pyrolysisModels PUBLIC radiationModels regionModels solidChemistryModel distributionModels)
