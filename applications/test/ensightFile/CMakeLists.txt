set(_FILES
  Test-ensightFile.C
)
add_executable(Test-ensightFile ${_FILES})
target_compile_features(Test-ensightFile PUBLIC cxx_std_11)
target_link_libraries(Test-ensightFile PUBLIC finiteVolume)
