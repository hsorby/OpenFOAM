set(_FILES
  Test-ListOps.C
)
add_executable(Test-ListOps ${_FILES})
target_compile_features(Test-ListOps PUBLIC cxx_std_11)
target_link_libraries(Test-ListOps PUBLIC finiteVolume)
