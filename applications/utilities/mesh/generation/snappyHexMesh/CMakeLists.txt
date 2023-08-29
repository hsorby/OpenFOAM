set(_FILES
  snappyHexMesh.C
)
add_executable(snappyHexMesh ${_FILES})
target_include_directories(snappyHexMesh PRIVATE includePrivate)
target_compile_features(snappyHexMesh PUBLIC cxx_std_11)
target_link_libraries(snappyHexMesh PUBLIC finiteVolume decompose reconstruct dynamicMesh snappyHexMeshLib)
