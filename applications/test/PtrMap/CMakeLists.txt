set(_FILES
  Test-PtrMap.C
)
add_executable(Test-PtrMap ${_FILES})
target_compile_features(Test-PtrMap PUBLIC cxx_std_11)
target_link_libraries(Test-PtrMap PUBLIC finiteVolume)
