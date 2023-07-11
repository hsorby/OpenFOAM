set(_FILES
  foamMeshToTet-vtk.C
  writeVTKtetMesh.C
)
add_executable(foamMeshToTet-vtk ${_FILES})
target_compile_features(foamMeshToTet-vtk PUBLIC cxx_std_11)
target_link_libraries(foamMeshToTet-vtk PUBLIC finiteVolume)
