set(_FILES
  Test-SubField.C
)
add_executable(Test-SubField ${_FILES})
target_compile_features(Test-SubField PUBLIC cxx_std_11)
target_link_libraries(Test-SubField PUBLIC finiteVolume)
