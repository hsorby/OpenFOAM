set(_FILES
  Test-PackedList1.C
)
add_executable(Test-PackedList1 ${_FILES})
target_compile_features(Test-PackedList1 PUBLIC cxx_std_11)
target_link_libraries(Test-PackedList1 PUBLIC finiteVolume)
