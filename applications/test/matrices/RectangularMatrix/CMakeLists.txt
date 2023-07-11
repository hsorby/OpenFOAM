set(_FILES
  Test-RectangularMatrix.C
)
add_executable(Test-RectangularMatrix ${_FILES})
target_compile_features(Test-RectangularMatrix PUBLIC cxx_std_11)
target_link_libraries(Test-RectangularMatrix PUBLIC finiteVolume)
