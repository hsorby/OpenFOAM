set(_FILES
  Test-HashTable3.C
)
add_executable(Test-HashTable3 ${_FILES})
target_compile_features(Test-HashTable3 PUBLIC cxx_std_11)
target_link_libraries(Test-HashTable3 PUBLIC finiteVolume)
