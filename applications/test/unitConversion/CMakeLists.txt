set(_FILES
  Test-unitConversion.C
)
add_executable(Test-unitConversion ${_FILES})
target_compile_features(Test-unitConversion PUBLIC cxx_std_11)
target_link_libraries(Test-unitConversion PUBLIC finiteVolume)
