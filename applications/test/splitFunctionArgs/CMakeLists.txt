set(_FILES
  Test-splitFunctionArgs.C
)
add_executable(Test-splitFunctionArgs ${_FILES})
target_compile_features(Test-splitFunctionArgs PUBLIC cxx_std_11)
target_link_libraries(Test-splitFunctionArgs PUBLIC finiteVolume)
