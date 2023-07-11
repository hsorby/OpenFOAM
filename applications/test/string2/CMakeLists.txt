set(_FILES
  Test-string2.C
)
add_executable(Test-string2 ${_FILES})
target_compile_features(Test-string2 PUBLIC cxx_std_11)
target_link_libraries(Test-string2 PUBLIC finiteVolume)
