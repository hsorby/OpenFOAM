set(_FILES
  pendulumAndSpring.C
)
add_executable(Test-pendulumAndSpring ${_FILES})
target_compile_features(Test-pendulumAndSpring PUBLIC cxx_std_11)
target_link_libraries(Test-pendulumAndSpring PUBLIC finiteVolume)
