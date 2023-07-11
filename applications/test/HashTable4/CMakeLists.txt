set(_FILES
  Test-HashTable4.C
)
add_executable(Test-HashTable4 ${_FILES})
target_compile_features(Test-HashTable4 PUBLIC cxx_std_11)
target_link_libraries(Test-HashTable4 PUBLIC finiteVolume)
