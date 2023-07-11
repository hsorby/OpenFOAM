set(_FILES
  Test-DynamicList2.C
)
add_executable(Test-DynamicList2 ${_FILES})
target_compile_features(Test-DynamicList2 PUBLIC cxx_std_11)
target_link_libraries(Test-DynamicList2 PUBLIC finiteVolume)
