set(_FILES
  writeFields.C
  checkTools.C
  checkTopology.C
  checkGeometry.C
  checkMeshQuality.C
  checkMesh.C
)
add_executable(checkMesh ${_FILES})
target_include_directories(checkMesh PRIVATE includePrivate)
target_compile_features(checkMesh PUBLIC cxx_std_11)
target_link_libraries(checkMesh PUBLIC dynamicMesh)
