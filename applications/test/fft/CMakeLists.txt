set(_FILES
  Test-fft.C
)
add_executable(Test-fft ${_FILES})
target_compile_features(Test-fft PUBLIC cxx_std_11)
target_link_libraries(Test-fft PUBLIC finiteVolume)
