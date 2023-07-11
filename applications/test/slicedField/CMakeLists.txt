set(_FILES
  Test-slicedField.C
)
add_executable(Test-slicedField ${_FILES})
target_compile_features(Test-slicedField PUBLIC cxx_std_11)
target_link_libraries(Test-slicedField PUBLIC finiteVolume)
