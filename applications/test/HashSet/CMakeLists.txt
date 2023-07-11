set(_FILES
  Test-hashSet.C
)
add_executable(Test-hashSet ${_FILES})
target_compile_features(Test-hashSet PUBLIC cxx_std_11)
target_link_libraries(Test-hashSet PUBLIC finiteVolume)
