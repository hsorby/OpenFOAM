set(_FILES
  Test-FieldFields2.C
)
add_executable(Test-FieldFields2 ${_FILES})
target_compile_features(Test-FieldFields2 PUBLIC cxx_std_11)
target_link_libraries(Test-FieldFields2 PUBLIC finiteVolume)
