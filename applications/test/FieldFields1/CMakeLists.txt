set(_FILES
  Test-FieldFields1.C
)
add_executable(Test-FieldFields1 ${_FILES})
target_compile_features(Test-FieldFields1 PUBLIC cxx_std_11)
target_link_libraries(Test-FieldFields1 PUBLIC finiteVolume)
