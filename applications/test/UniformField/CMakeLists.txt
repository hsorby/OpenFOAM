set(_FILES
  Test-UniformField.C
)
add_executable(Test-UniformField ${_FILES})
target_compile_features(Test-UniformField PUBLIC cxx_std_11)
target_link_libraries(Test-UniformField PUBLIC finiteVolume)
