set(_FILES
  Test-OCountStream.C
)
add_executable(Test-OCountStream ${_FILES})
target_compile_features(Test-OCountStream PUBLIC cxx_std_11)
target_link_libraries(Test-OCountStream PUBLIC finiteVolume)
