set(_FILES
  Test-tensor2D.C
)
add_executable(Test-tensor2D ${_FILES})
target_compile_features(Test-tensor2D PUBLIC cxx_std_11)
target_link_libraries(Test-tensor2D PUBLIC finiteVolume)
