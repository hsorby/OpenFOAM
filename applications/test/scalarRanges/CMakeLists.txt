set(_FILES
  Test-scalarRanges.C
)
add_executable(Test-scalarRanges ${_FILES})
target_compile_features(Test-scalarRanges PUBLIC cxx_std_11)
target_link_libraries(Test-scalarRanges PUBLIC finiteVolume)
