set(_FILES
  distributedTriSurfaceMesh/distributedTriSurfaceMesh.C
  patchDistMethods/exact/exactPatchDistMethod.C
)
add_library(distributed ${_FILES})
target_compile_features(distributed PUBLIC cxx_std_11)
target_include_directories(distributed PUBLIC include PRIVATE includePrivate)
