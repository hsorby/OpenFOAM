set(_FILES
  Test-SHA1.C
)
add_executable(Test-SHA1 ${_FILES})
target_compile_features(Test-SHA1 PUBLIC cxx_std_11)
target_link_libraries(Test-SHA1 PUBLIC finiteVolume)
