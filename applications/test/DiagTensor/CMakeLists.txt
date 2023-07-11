set(_FILES
  Test-DiagTensor.C
)
add_executable(Test-DiagTensor ${_FILES})
target_compile_features(Test-DiagTensor PUBLIC cxx_std_11)
target_link_libraries(Test-DiagTensor PUBLIC finiteVolume)
