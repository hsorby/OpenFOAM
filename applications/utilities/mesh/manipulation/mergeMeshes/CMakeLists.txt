set(_FILES
  mergeMeshes.C
  mergePolyMesh.C
)
add_executable(mergeMeshes ${_FILES})
target_compile_features(mergeMeshes PUBLIC cxx_std_11)
target_include_directories(mergeMeshes PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mergeMeshes PUBLIC dynamicMesh reconstruct)
