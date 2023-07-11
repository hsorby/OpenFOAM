set(_FILES
  Test-PatchEdgeFaceWave.C
)
add_executable(Test-PatchEdgeFaceWave ${_FILES})
target_compile_features(Test-PatchEdgeFaceWave PUBLIC cxx_std_11)
target_link_libraries(Test-PatchEdgeFaceWave PUBLIC finiteVolume)
