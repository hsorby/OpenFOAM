set(_FILES
  Test-parallel-nonBlocking.C
)
add_executable(Test-parallel-nonBlocking ${_FILES})
target_compile_features(Test-parallel-nonBlocking PUBLIC cxx_std_11)
target_link_libraries(Test-parallel-nonBlocking PUBLIC finiteVolume)
