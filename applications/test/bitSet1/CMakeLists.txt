set(_FILES
  Test-bitSet1.C
)
add_executable(Test-bitSet1 ${_FILES})
target_compile_features(Test-bitSet1 PUBLIC cxx_std_11)
target_link_libraries(Test-bitSet1 PUBLIC finiteVolume)
