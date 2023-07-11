set(_FILES
  Test-DynamicList.C
)
add_executable(Test-DynamicList ${_FILES})
target_compile_features(Test-DynamicList PUBLIC cxx_std_11)
target_link_libraries(Test-DynamicList PUBLIC finiteVolume)
