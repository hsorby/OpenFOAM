set(_FILES
  Test-HashTable2.C
)
add_executable(Test-HashTable2 ${_FILES})
target_compile_features(Test-HashTable2 PUBLIC cxx_std_11)
target_link_libraries(Test-HashTable2 PUBLIC finiteVolume)
