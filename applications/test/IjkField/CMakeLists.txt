set(_FILES
  Test-IjkField.C
)
add_executable(Test-IjkField ${_FILES})
target_compile_features(Test-IjkField PUBLIC cxx_std_11)
target_link_libraries(Test-IjkField PUBLIC finiteVolume)
