set(_FILES
  saturationModel/saturationModel.C
  Antoine/Antoine.C
  AntoineExtended/AntoineExtended.C
  ArdenBuck/ArdenBuck.C
  polynomial/polynomial.C
  function1/function1.C
  constantSaturationConditions/constantSaturationConditions.C
)
add_library(saturationModel ${_FILES})
target_compile_features(saturationModel PUBLIC cxx_std_11)
target_include_directories(saturationModel PUBLIC include includePrivate)
target_link_libraries(saturationModel PUBLIC finiteVolume)
