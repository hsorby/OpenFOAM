set(_FILES
  Test-bitops.C
)
add_executable(Test-bitops ${_FILES})
target_compile_features(Test-bitops PUBLIC cxx_std_11)
target_link_libraries(Test-bitops PUBLIC finiteVolume)
