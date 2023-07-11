set(_FILES
  Test-SquareMatrix.C
)
add_executable(Test-SquareMatrix ${_FILES})
target_compile_features(Test-SquareMatrix PUBLIC cxx_std_11)
target_link_libraries(Test-SquareMatrix PUBLIC finiteVolume)
