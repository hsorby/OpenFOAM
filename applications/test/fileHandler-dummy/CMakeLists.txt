set(_FILES
  Test-fileHandler-dummy.C
)
add_executable(Test-fileHandler-dummy ${_FILES})
target_compile_features(Test-fileHandler-dummy PUBLIC cxx_std_11)
target_link_libraries(Test-fileHandler-dummy PUBLIC finiteVolume)
