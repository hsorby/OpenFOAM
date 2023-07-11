set(_FILES
  Test-mapDistributePolyMesh.C
)
add_executable(Test-mapDistributePolyMesh ${_FILES})
target_compile_features(Test-mapDistributePolyMesh PUBLIC cxx_std_11)
target_link_libraries(Test-mapDistributePolyMesh PUBLIC finiteVolume)
