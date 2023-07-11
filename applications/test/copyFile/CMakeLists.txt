set(_FILES
  Test-copyFile.C
)
add_executable(Test-copyFile ${_FILES})
target_compile_features(Test-copyFile PUBLIC cxx_std_11)
target_link_libraries(Test-copyFile PUBLIC finiteVolume)
