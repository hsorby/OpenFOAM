set(_FILES
  Test-parallel-comm1.C
)
add_executable(Test-parallel-comm1 ${_FILES})
target_compile_features(Test-parallel-comm1 PUBLIC cxx_std_11)
target_link_libraries(Test-parallel-comm1 PUBLIC finiteVolume)
