set(_FILES
  Test-charList.C
)
add_executable(Test-charList ${_FILES})
target_compile_features(Test-charList PUBLIC cxx_std_11)
target_link_libraries(Test-charList PUBLIC finiteVolume)
