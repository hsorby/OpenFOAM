set(_FILES
  Test-cstring.C
)
add_executable(Test-cstring ${_FILES})
target_compile_features(Test-cstring PUBLIC cxx_std_11)
target_link_libraries(Test-cstring PUBLIC finiteVolume)
