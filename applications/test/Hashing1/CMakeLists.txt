set(_FILES
  Test-Hashing1.C
)
add_executable(Test-Hashing1 ${_FILES})
target_compile_features(Test-Hashing1 PUBLIC cxx_std_11)
target_link_libraries(Test-Hashing1 PUBLIC finiteVolume)
