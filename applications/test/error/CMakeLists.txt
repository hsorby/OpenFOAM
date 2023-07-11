set(_FILES
  Test-error.C
)
add_executable(Test-error ${_FILES})
target_compile_features(Test-error PUBLIC cxx_std_11)
target_link_libraries(Test-error PUBLIC finiteVolume)
