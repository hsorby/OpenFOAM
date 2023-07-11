set(_FILES
  Test-IListStream.C
)
add_executable(Test-IListStream ${_FILES})
target_compile_features(Test-IListStream PUBLIC cxx_std_11)
target_link_libraries(Test-IListStream PUBLIC finiteVolume)
