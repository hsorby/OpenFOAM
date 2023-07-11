set(_FILES
  Test-globalMeshData.C
)
add_executable(Test-globalMeshData ${_FILES})
target_compile_features(Test-globalMeshData PUBLIC cxx_std_11)
target_link_libraries(Test-globalMeshData PUBLIC finiteVolume)
