set(_FILES
  Test-clock.C
)
add_executable(Test-clock ${_FILES})
target_compile_features(Test-clock PUBLIC cxx_std_11)
target_link_libraries(Test-clock PUBLIC finiteVolume)
