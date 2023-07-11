set(_FILES
  Test-Tensor2D.C
)
add_executable(Test-Tensor2D ${_FILES})
target_compile_features(Test-Tensor2D PUBLIC cxx_std_11)
target_link_libraries(Test-Tensor2D PUBLIC finiteVolume)
