set(_FILES
  Test-surfaceTree.C
)
add_executable(Test-surfaceTree ${_FILES})
target_compile_features(Test-surfaceTree PUBLIC cxx_std_11)
target_link_libraries(Test-surfaceTree PUBLIC finiteVolume)
