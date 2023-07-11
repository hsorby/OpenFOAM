set(_FILES
  Test-dictionary2.C
)
add_executable(Test-dictionary2 ${_FILES})
target_compile_features(Test-dictionary2 PUBLIC cxx_std_11)
target_link_libraries(Test-dictionary2 PUBLIC finiteVolume)
