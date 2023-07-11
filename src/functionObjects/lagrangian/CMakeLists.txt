set(_FILES
  common/parcelSelectionDetail.C
  dataCloud/dataCloud.C
  cloudInfo/cloudInfo.C
  icoUncoupledKinematicCloud/icoUncoupledKinematicCloud.C
  dsmcFields/dsmcFields.C
  vtkCloud/vtkCloud.C
)
add_library(lagrangianFunctionObjects ${_FILES})
target_compile_features(lagrangianFunctionObjects PUBLIC cxx_std_11)
target_include_directories(lagrangianFunctionObjects PUBLIC include PRIVATE includePrivate)
