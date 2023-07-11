set(_FILES
  Test-parallel-broadcast.C
)
add_executable(Test-parallel-broadcast ${_FILES})
target_compile_features(Test-parallel-broadcast PUBLIC cxx_std_11)
target_link_libraries(Test-parallel-broadcast PUBLIC finiteVolume)
