set(_FILES
  Test-UDictionary.C
)
add_executable(Test-UDictionary ${_FILES})
target_compile_features(Test-UDictionary PUBLIC cxx_std_11)
target_link_libraries(Test-UDictionary PUBLIC finiteVolume)
