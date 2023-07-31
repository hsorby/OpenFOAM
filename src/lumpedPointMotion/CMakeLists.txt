set(_FILES
  controller/lumpedPointController.C
  state/lumpedPointState.C
  state/lumpedPointStateWriter.C
  movement/lumpedPointMovement.C
  movement/lumpedPointMovementWriter.C
  movement/lumpedPointIOMovement.C
  tools/lumpedPointTools.C
  pointPatchFields/lumpedPointDisplacementPointPatchVectorField.C
)
add_library(lumpedPointMotion ${_FILES})
target_compile_features(lumpedPointMotion PUBLIC cxx_std_11)
target_include_directories(lumpedPointMotion PUBLIC include PRIVATE includePrivate)
target_link_libraries(lumpedPointMotion PUBLIC finiteVolume dynamicMesh)
