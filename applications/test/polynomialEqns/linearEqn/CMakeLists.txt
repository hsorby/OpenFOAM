set(_FILES
  Test-linearEqn.C
)
add_executable(Test-linearEqn ${_FILES})
target_compile_features(Test-linearEqn PUBLIC cxx_std_11)
target_link_libraries(Test-linearEqn PUBLIC finiteVolume)
