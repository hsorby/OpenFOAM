set(_FILES
  common/genericPatchFieldBase.C
  genericFaPatchField/genericFaPatchFields.C
  genericFvPatchField/genericFvPatchFields.C
  genericFvsPatchField/genericFvsPatchFields.C
  genericPointPatchField/genericPointPatchFields.C
)
add_library(genericPatchFields ${_FILES})
target_compile_features(genericPatchFields PUBLIC cxx_std_11)
target_include_directories(genericPatchFields PUBLIC
  include
  includePrivate
  common
  genericFaPatchField
  genericFaePatchField
  genericFvPatchField
  genericFvsPatchField
  genericPointPatchField
)
target_link_libraries(genericPatchFields PUBLIC OpenFOAM finiteArea finiteVolume)
