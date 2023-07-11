set(_FILES
  Test-List2.C
)
add_executable(Test-List2 ${_FILES})
target_compile_features(Test-List2 PUBLIC cxx_std_11)
target_link_libraries(Test-List2 PUBLIC finiteVolume)
