set(_FILES
  Test-parallel-nbx2.C
)
add_executable(Test-parallel-nbx2 ${_FILES})
target_compile_features(Test-parallel-nbx2 PUBLIC cxx_std_11)
target_link_libraries(Test-parallel-nbx2 PUBLIC finiteVolume)
