set(_FILES
  Test-write-wrapped-string.C
)
add_executable(Test-write-wrapped-string ${_FILES})
target_compile_features(Test-write-wrapped-string PUBLIC cxx_std_11)
target_link_libraries(Test-write-wrapped-string PUBLIC finiteVolume)
