set(_FILES
  Test-surfaceIntersection.C
)
add_executable(Test-surfaceIntersection ${_FILES})
target_compile_features(Test-surfaceIntersection PUBLIC cxx_std_11)
target_link_libraries(Test-surfaceIntersection PUBLIC finiteVolume)
