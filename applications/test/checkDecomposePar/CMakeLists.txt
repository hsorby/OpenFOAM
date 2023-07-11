set(_FILES
  Test-checkDecomposePar.C
)
add_executable(Test-checkDecomposePar ${_FILES})
target_compile_features(Test-checkDecomposePar PUBLIC cxx_std_11)
target_link_libraries(Test-checkDecomposePar PUBLIC finiteVolume)
