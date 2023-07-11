set(_FILES
  Test-IntRange.C
)
add_executable(Test-IntRange ${_FILES})
target_compile_features(Test-IntRange PUBLIC cxx_std_11)
target_link_libraries(Test-IntRange PUBLIC finiteVolume)
