set(_FILES
  Test-maxMem.C
)
add_executable(Test-maxMem ${_FILES})
target_compile_features(Test-maxMem PUBLIC cxx_std_11)
target_link_libraries(Test-maxMem PUBLIC finiteVolume)
