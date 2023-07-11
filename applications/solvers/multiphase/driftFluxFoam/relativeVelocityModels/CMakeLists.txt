set(_FILES
  relativeVelocityModel/relativeVelocityModel.C
  simple/simple.C
  general/general.C
)
add_library(driftFluxRelativeVelocityModels ${_FILES})
target_compile_features(driftFluxRelativeVelocityModels PUBLIC cxx_std_11)
target_include_directories(driftFluxRelativeVelocityModels PUBLIC include PRIVATE includePrivate)
