set(_FILES
  Test-sliceRange.C
)
add_executable(Test-sliceRange ${_FILES})
target_compile_features(Test-sliceRange PUBLIC cxx_std_11)
target_link_libraries(Test-sliceRange PUBLIC finiteVolume)
