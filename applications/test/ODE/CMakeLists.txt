set(_FILES
  Test-ODE.C
)
add_executable(Test-ODE ${_FILES})
target_compile_features(Test-ODE PUBLIC cxx_std_11)
target_link_libraries(Test-ODE PUBLIC finiteVolume)
