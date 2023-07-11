set(_FILES
  Test-cubicEqn.C
)
add_executable(Test-cubicEqn ${_FILES})
target_compile_features(Test-cubicEqn PUBLIC cxx_std_11)
target_link_libraries(Test-cubicEqn PUBLIC finiteVolume)
