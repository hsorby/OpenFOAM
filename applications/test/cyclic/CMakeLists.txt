set(_FILES
  Test-cyclic.C
)
add_executable(Test-cyclic ${_FILES})
target_compile_features(Test-cyclic PUBLIC cxx_std_11)
target_link_libraries(Test-cyclic PUBLIC finiteVolume)
