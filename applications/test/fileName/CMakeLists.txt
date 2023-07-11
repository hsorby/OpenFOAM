set(_FILES
  Test-fileName.C
)
add_executable(Test-fileName ${_FILES})
target_compile_features(Test-fileName PUBLIC cxx_std_11)
target_link_libraries(Test-fileName PUBLIC finiteVolume)
