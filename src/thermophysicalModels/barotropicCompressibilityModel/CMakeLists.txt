set(_FILES
  barotropicCompressibilityModel/barotropicCompressibilityModel.C
  barotropicCompressibilityModel/barotropicCompressibilityModelNew.C
  linear/linear.C
  Wallis/Wallis.C
  Chung/Chung.C
)
add_library(barotropicCompressibilityModel ${_FILES})
target_compile_features(barotropicCompressibilityModel PUBLIC cxx_std_11)
target_include_directories(barotropicCompressibilityModel PUBLIC include PRIVATE includePrivate)
