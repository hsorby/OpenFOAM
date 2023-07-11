set(_FILES
  Test-token.C
)
add_executable(Test-token ${_FILES})
target_compile_features(Test-token PUBLIC cxx_std_11)
target_link_libraries(Test-token PUBLIC finiteVolume)
