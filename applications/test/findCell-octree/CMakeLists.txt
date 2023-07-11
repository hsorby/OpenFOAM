set(_FILES
  Test-findCell-octree.C
)
add_executable(Test-findCell-octree ${_FILES})
target_compile_features(Test-findCell-octree PUBLIC cxx_std_11)
target_link_libraries(Test-findCell-octree PUBLIC finiteVolume)
