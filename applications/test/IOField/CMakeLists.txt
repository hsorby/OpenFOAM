set(_FILES
  Test-IOField.C
)
add_executable(Test-IOField ${_FILES})
target_compile_features(Test-IOField PUBLIC cxx_std_11)
target_link_libraries(Test-IOField PUBLIC finiteVolume)
