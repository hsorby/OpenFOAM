set(_FILES
  extrudedMesh/extrudedMesh.C
  extrudeMesh.C
)
add_executable(extrudeMesh ${_FILES})
target_include_directories(extrudeMesh PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/extrudedMesh)
target_compile_features(extrudeMesh PUBLIC cxx_std_11)
target_link_libraries(extrudeMesh PUBLIC finiteVolume dynamicMesh extrudeModel reconstruct)
