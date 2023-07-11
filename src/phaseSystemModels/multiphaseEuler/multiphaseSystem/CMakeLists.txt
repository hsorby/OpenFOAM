set(_FILES
  phaseModel/phaseModel.C
  multiphaseSystem/multiphaseSystem.C
  diameterModels/diameterModel/diameterModel.C
  diameterModels/constantDiameter/constantDiameter.C
  diameterModels/isothermalDiameter/isothermalDiameter.C
  interfacialModels/dragModels/dragModel/dragModel.C
  interfacialModels/dragModels/Ergun/Ergun.C
  interfacialModels/dragModels/GidaspowErgunWenYu/GidaspowErgunWenYu.C
  interfacialModels/dragModels/GidaspowSchillerNaumann/GidaspowSchillerNaumann.C
  interfacialModels/dragModels/SchillerNaumann/SchillerNaumann.C
  interfacialModels/dragModels/Gibilaro/Gibilaro.C
  interfacialModels/dragModels/WenYu/WenYu.C
  interfacialModels/dragModels/SyamlalOBrien/SyamlalOBrien.C
  interfacialModels/dragModels/blended/blended.C
  interfacialModels/dragModels/interface/interface.C
  interfacialModels/heatTransferModels/heatTransferModel/heatTransferModel.C
  interfacialModels/heatTransferModels/RanzMarshall/RanzMarshall.C
  derivedFvPatchFields/alphaContactAngle/alphaContactAngleFvPatchScalarField.C
)
add_library(multiphaseSystem ${_FILES})
target_compile_features(multiphaseSystem PUBLIC cxx_std_11)
target_include_directories(multiphaseSystem PUBLIC include PRIVATE includePrivate)
