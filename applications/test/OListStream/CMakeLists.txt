set(_FILES
  Test-OListStream.C
)
add_executable(Test-OListStream ${_FILES})
target_compile_features(Test-OListStream PUBLIC cxx_std_11)
target_link_libraries(Test-OListStream PUBLIC finiteVolume)
