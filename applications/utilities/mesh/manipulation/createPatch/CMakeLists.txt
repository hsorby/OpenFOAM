set(_FILES
  createPatch.C
)
add_executable(createPatch ${_FILES})
target_compile_features(createPatch PUBLIC cxx_std_11)
target_link_libraries(createPatch PUBLIC dynamicMesh reconstruct)
