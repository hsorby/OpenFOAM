set(_FILES
  Test-DynamicField.C
)
add_executable(Test-DynamicField ${_FILES})
target_compile_features(Test-DynamicField PUBLIC cxx_std_11)
target_link_libraries(Test-DynamicField PUBLIC finiteVolume)
