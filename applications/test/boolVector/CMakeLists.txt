set(_FILES
  Test-boolVector.C
)
add_executable(Test-boolVector ${_FILES})
target_compile_features(Test-boolVector PUBLIC cxx_std_11)
target_link_libraries(Test-boolVector PUBLIC finiteVolume)
