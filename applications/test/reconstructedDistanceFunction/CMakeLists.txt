set(_FILES
  Test-reconstructedDistanceFunction.C
)
add_executable(Test-reconstructedDistanceFunction ${_FILES})
target_compile_features(Test-reconstructedDistanceFunction PUBLIC cxx_std_11)
target_link_libraries(Test-reconstructedDistanceFunction PUBLIC finiteVolume)
