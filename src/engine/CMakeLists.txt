set(_FILES
  engineTime/engineTime/engineTime.C
  engineTime/engineTime/engineTimeNew.C
  engineTime/freePiston/freePiston.C
  engineTime/crankConRod/crankConRod.C
  ignition/ignition.C
  ignition/ignitionIO.C
  ignition/ignitionSite.C
  ignition/ignitionSiteIO.C
  engineValve/engineValve.C
  enginePiston/enginePiston.C
  engineMesh/engineMesh/engineMesh.C
  engineMesh/engineMesh/engineMeshNew.C
  engineMesh/staticEngineMesh/staticEngineMesh.C
  engineMesh/layeredEngineMesh/layeredEngineMesh.C
  engineMesh/fvMotionSolverEngineMesh/fvMotionSolverEngineMesh.C
)
add_library(engine ${_FILES})
target_compile_features(engine PUBLIC cxx_std_11)
target_include_directories(engine PUBLIC include PRIVATE includePrivate)
