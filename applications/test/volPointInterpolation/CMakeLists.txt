set(_FILES
  Test-volPointInterpolation.C
)
add_executable(Test-volPointInterpolation ${_FILES})
target_compile_features(Test-volPointInterpolation PUBLIC cxx_std_11)
target_link_libraries(Test-volPointInterpolation PUBLIC finiteVolume)
