set(_FILES
  dynamicFvMesh/dynamicFvMesh.C
  dynamicFvMesh/dynamicFvMeshNew.C
  staticFvMesh/staticFvMesh.C
  dynamicMotionSolverFvMesh/dynamicMotionSolverFvMesh.C
  dynamicMultiMotionSolverFvMesh/dynamicMultiMotionSolverFvMesh.C
  dynamicInkJetFvMesh/dynamicInkJetFvMesh.C
  dynamicRefineFvMesh/dynamicRefineFvMesh.C
  dynamicMotionSolverListFvMesh/dynamicMotionSolverListFvMesh.C
  simplifiedDynamicFvMesh/simplifiedDynamicFvMeshes.C
  simplifiedDynamicFvMesh/simplifiedDynamicFvMesh.C
  dynamicMotionSolverFvMeshAMI/dynamicMotionSolverFvMeshAMI.C
)
add_library(dynamicFvMesh ${_FILES})
target_compile_features(dynamicFvMesh PUBLIC cxx_std_11)
target_include_directories(dynamicFvMesh PUBLIC include PRIVATE includePrivate)
