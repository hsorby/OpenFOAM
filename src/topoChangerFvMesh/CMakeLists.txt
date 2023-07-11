set(_FILES
  topoChangerFvMesh/topoChangerFvMesh.C
  rawTopoChangerFvMesh/rawTopoChangerFvMesh.C
  dynamicMotionSolverTopoFvMesh/dynamicMotionSolverTopoFvMesh.C
  linearValveFvMesh/linearValveFvMesh.C
  linearValveLayersFvMesh/linearValveLayersFvMesh.C
  movingConeTopoFvMesh/movingConeTopoFvMesh.C
  mixerFvMesh/mixerFvMesh.C
)
add_library(topoChangerFvMesh ${_FILES})
target_compile_features(topoChangerFvMesh PUBLIC cxx_std_11)
target_include_directories(topoChangerFvMesh PUBLIC include PRIVATE includePrivate)
