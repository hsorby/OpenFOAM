set(_FILES
  Test-tensorFields1.C
)
add_executable(Test-tensorFields1 ${_FILES})
target_compile_features(Test-tensorFields1 PUBLIC cxx_std_11)
target_link_libraries(Test-tensorFields1 PUBLIC finiteVolume)
