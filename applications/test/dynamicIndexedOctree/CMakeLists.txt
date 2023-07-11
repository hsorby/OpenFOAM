set(_FILES
  Test-dynamicIndexedOctree.C
)
add_executable(Test-dynamicIndexedOctree ${_FILES})
target_compile_features(Test-dynamicIndexedOctree PUBLIC cxx_std_11)
target_link_libraries(Test-dynamicIndexedOctree PUBLIC finiteVolume)
