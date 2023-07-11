set(_FILES
  Test-minMax1.C
)
add_executable(Test-minMax1 ${_FILES})
target_compile_features(Test-minMax1 PUBLIC cxx_std_11)
target_link_libraries(Test-minMax1 PUBLIC finiteVolume)
