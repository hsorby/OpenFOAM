set(_FILES
  Test-regex1.C
)
add_executable(Test-regex1 ${_FILES})
target_compile_features(Test-regex1 PUBLIC cxx_std_11)
target_link_libraries(Test-regex1 PUBLIC finiteVolume)
