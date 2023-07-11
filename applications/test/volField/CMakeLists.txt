set(_FILES
  Test-volField.C
)
add_executable(Test-volField ${_FILES})
target_compile_features(Test-volField PUBLIC cxx_std_11)
target_link_libraries(Test-volField PUBLIC finiteVolume)
