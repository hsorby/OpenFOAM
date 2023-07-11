set(_FILES
  Test-parallel-comm0.C
)
add_executable(Test-parallel-comm0 ${_FILES})
target_compile_features(Test-parallel-comm0 PUBLIC cxx_std_11)
target_link_libraries(Test-parallel-comm0 PUBLIC finiteVolume)
