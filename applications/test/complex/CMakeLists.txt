set(_FILES
  Test-complex.C
)
add_executable(Test-complex ${_FILES})
target_compile_features(Test-complex PUBLIC cxx_std_11)
target_link_libraries(Test-complex PUBLIC finiteVolume)
