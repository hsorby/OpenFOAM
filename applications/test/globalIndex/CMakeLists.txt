set(_FILES
  Test-globalIndex.C
)
add_executable(Test-globalIndex ${_FILES})
target_compile_features(Test-globalIndex PUBLIC cxx_std_11)
target_link_libraries(Test-globalIndex PUBLIC finiteVolume)
