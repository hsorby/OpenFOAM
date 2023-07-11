set(_FILES
  Test-PrecisionAdaptor.C
)
add_executable(Test-PrecisionAdaptor ${_FILES})
target_compile_features(Test-PrecisionAdaptor PUBLIC cxx_std_11)
target_link_libraries(Test-PrecisionAdaptor PUBLIC finiteVolume)
