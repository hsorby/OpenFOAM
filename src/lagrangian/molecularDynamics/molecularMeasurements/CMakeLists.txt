set(_FILES
  distribution/distribution.C
)
add_library(molecularMeasurements ${_FILES})
target_compile_features(molecularMeasurements PUBLIC cxx_std_11)
target_include_directories(molecularMeasurements PUBLIC include PRIVATE includePrivate)
