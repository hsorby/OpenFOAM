set(_FILES
  fvMeshGeometry.C
  fvMesh.C
  Test-fieldMapping.C
)
add_executable(Test-fieldMapping ${_FILES})
target_compile_features(Test-fieldMapping PUBLIC cxx_std_11)
target_link_libraries(Test-fieldMapping PUBLIC finiteVolume)
