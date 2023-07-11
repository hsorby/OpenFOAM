set(_FILES
  phase/phase.C
  alphaContactAngle/alphaContactAngleFvPatchScalarField.C
  multiphaseMixture.C
)
add_library(multiphaseInterFoam ${_FILES})
target_compile_features(multiphaseInterFoam PUBLIC cxx_std_11)
target_include_directories(multiphaseInterFoam PUBLIC include PRIVATE includePrivate)
