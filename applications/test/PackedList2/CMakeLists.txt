set(_FILES
  Test-PackedList2.C
)
add_executable(Test-PackedList2 ${_FILES})
target_compile_features(Test-PackedList2 PUBLIC cxx_std_11)
target_link_libraries(Test-PackedList2 PUBLIC finiteVolume)
