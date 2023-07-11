set(_FILES
  Test-UIndirectList.C
)
add_executable(Test-UIndirectList ${_FILES})
target_compile_features(Test-UIndirectList PUBLIC cxx_std_11)
target_link_libraries(Test-UIndirectList PUBLIC finiteVolume)
