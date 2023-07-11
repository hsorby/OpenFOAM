set(_FILES
  Test-dictionary3.C
)
add_executable(Test-dictionary3 ${_FILES})
target_compile_features(Test-dictionary3 PUBLIC cxx_std_11)
target_link_libraries(Test-dictionary3 PUBLIC finiteVolume)
