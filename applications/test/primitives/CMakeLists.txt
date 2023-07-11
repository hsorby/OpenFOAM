set(_FILES
  Test-primitives.C
)
add_executable(Test-primitives ${_FILES})
target_compile_features(Test-primitives PUBLIC cxx_std_11)
target_link_libraries(Test-primitives PUBLIC finiteVolume)
