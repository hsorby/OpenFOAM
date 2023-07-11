set(_FILES
  Test-leastSquareGrad.C
)
add_executable(Test-leastSquareGrad ${_FILES})
target_compile_features(Test-leastSquareGrad PUBLIC cxx_std_11)
target_link_libraries(Test-leastSquareGrad PUBLIC finiteVolume)
