set(_FILES
  Test-SymmetricSquareMatrix.C
)
add_executable(Test-SymmetricSquareMatrix ${_FILES})
target_compile_features(Test-SymmetricSquareMatrix PUBLIC cxx_std_11)
target_link_libraries(Test-SymmetricSquareMatrix PUBLIC finiteVolume)
