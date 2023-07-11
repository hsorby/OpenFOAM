set(_FILES
  rigidBodyMeshMotion/rigidBodyMeshMotion.C
  rigidBodyMeshMotionSolver/rigidBodyMeshMotionSolver.C
)
add_library(rigidBodyMeshMotion ${_FILES})
target_compile_features(rigidBodyMeshMotion PUBLIC cxx_std_11)
target_include_directories(rigidBodyMeshMotion PUBLIC include PRIVATE includePrivate)
