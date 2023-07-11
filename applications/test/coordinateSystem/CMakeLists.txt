set(_FILES
  Test-coordinateSystem.C
)
add_executable(Test-coordinateSystem ${_FILES})
target_compile_features(Test-coordinateSystem PUBLIC cxx_std_11)
target_link_libraries(Test-coordinateSystem PUBLIC finiteVolume)
