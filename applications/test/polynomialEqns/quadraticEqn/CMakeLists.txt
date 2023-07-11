set(_FILES
  Test-quadraticEqn.C
)
add_executable(Test-quadraticEqn ${_FILES})
target_compile_features(Test-quadraticEqn PUBLIC cxx_std_11)
target_link_libraries(Test-quadraticEqn PUBLIC finiteVolume)
