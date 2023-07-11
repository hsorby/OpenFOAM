set(_FILES
  Test-syncTools.C
)
add_executable(Test-syncTools ${_FILES})
target_compile_features(Test-syncTools PUBLIC cxx_std_11)
target_link_libraries(Test-syncTools PUBLIC finiteVolume)
