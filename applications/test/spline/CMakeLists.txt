set(_FILES
  Test-spline.C
)
add_executable(Test-spline ${_FILES})
target_compile_features(Test-spline PUBLIC cxx_std_11)
target_link_libraries(Test-spline PUBLIC finiteVolume)
