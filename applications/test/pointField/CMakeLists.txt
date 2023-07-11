set(_FILES
  Test-PointField.C
)
add_executable(Test-pointField ${_FILES})
target_compile_features(Test-pointField PUBLIC cxx_std_11)
target_link_libraries(Test-pointField PUBLIC finiteVolume)
