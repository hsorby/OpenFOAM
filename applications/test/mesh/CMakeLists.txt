set(_FILES
  Test-mesh.C
)
add_executable(Test-mesh ${_FILES})
target_compile_features(Test-mesh PUBLIC cxx_std_11)
target_link_libraries(Test-mesh PUBLIC finiteVolume)
