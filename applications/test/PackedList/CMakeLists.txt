set(_FILES
  Test-PackedList.C
)
add_executable(Test-PackedList ${_FILES})
target_compile_features(Test-PackedList PUBLIC cxx_std_11)
target_link_libraries(Test-PackedList PUBLIC finiteVolume)
