set(_FILES
  Test-UIListStream.C
)
add_executable(Test-UIListStream ${_FILES})
target_compile_features(Test-UIListStream PUBLIC cxx_std_11)
target_link_libraries(Test-UIListStream PUBLIC finiteVolume)
