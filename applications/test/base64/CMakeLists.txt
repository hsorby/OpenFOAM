set(_FILES
  Test-base64Encoding.C
)
add_executable(Test-base64Encoding ${_FILES})
target_compile_features(Test-base64Encoding PUBLIC cxx_std_11)
target_link_libraries(Test-base64Encoding PUBLIC finiteVolume)
