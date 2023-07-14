set(_FILES
  distributionModel/distributionModel.C
  distributionModel/distributionModelNew.C
  binned/binned.C
  exponential/exponential.C
  fixedValue/fixedValue.C
  general/general.C
  multiNormal/multiNormal.C
  normal/normal.C
  RosinRammler/RosinRammler.C
  massRosinRammler/massRosinRammler.C
  uniform/uniform.C
)
add_library(distributionModels ${_FILES})
target_compile_features(distributionModels PUBLIC cxx_std_11)
target_include_directories(distributionModels PUBLIC include PRIVATE includePrivate)
target_link_libraries(distributionModels PUBLIC OpenFOAM lagrangian)
