set(_FILES
  Test-triangleIntersection.C
)
add_executable(Test-triangleIntersection ${_FILES})
target_compile_features(Test-triangleIntersection PUBLIC cxx_std_11)
target_link_libraries(Test-triangleIntersection PUBLIC finiteVolume)
