set(_FILES
  Test-sortList.C
)
add_executable(Test-sortList ${_FILES})
target_compile_features(Test-sortList PUBLIC cxx_std_11)
target_link_libraries(Test-sortList PUBLIC finiteVolume)
