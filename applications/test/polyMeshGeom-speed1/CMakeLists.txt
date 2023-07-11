set(_FILES
  Test-polyMeshGeom-speed1.C
)
add_executable(Test-polyMeshGeom-speed1 ${_FILES})
target_compile_features(Test-polyMeshGeom-speed1 PUBLIC cxx_std_11)
target_link_libraries(Test-polyMeshGeom-speed1 PUBLIC finiteVolume)
