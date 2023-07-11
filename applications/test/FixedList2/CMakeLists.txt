set(_FILES
  Test-FixedList2.C
)
add_executable(Test-FixedList2 ${_FILES})
target_compile_features(Test-FixedList2 PUBLIC cxx_std_11)
target_link_libraries(Test-FixedList2 PUBLIC finiteVolume)
