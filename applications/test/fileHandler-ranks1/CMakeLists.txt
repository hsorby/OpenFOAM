set(_FILES
  Test-fileHandler-ranks1.C
)
add_executable(Test-fileHandler-ranks1 ${_FILES})
target_compile_features(Test-fileHandler-ranks1 PUBLIC cxx_std_11)
target_link_libraries(Test-fileHandler-ranks1 PUBLIC finiteVolume)
