set(_FILES
  Test-Dictionary.C
)
add_executable(Test-Dictionary ${_FILES})
target_compile_features(Test-Dictionary PUBLIC cxx_std_11)
target_link_libraries(Test-Dictionary PUBLIC finiteVolume)
