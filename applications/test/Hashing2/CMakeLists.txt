set(_FILES
  Test-Hashing2.C
)
add_executable(Test-Hashing2 ${_FILES})
target_compile_features(Test-Hashing2 PUBLIC cxx_std_11)
target_link_libraries(Test-Hashing2 PUBLIC finiteVolume)
