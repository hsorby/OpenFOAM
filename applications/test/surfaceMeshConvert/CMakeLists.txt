set(_FILES
  Test-surfaceMeshConvert.C
)
add_executable(Test-surfaceMeshConvert ${_FILES})
target_compile_features(Test-surfaceMeshConvert PUBLIC cxx_std_11)
target_link_libraries(Test-surfaceMeshConvert PUBLIC finiteVolume)
