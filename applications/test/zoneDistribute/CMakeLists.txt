set(_FILES
  Test-zoneDistribute.C
)
add_executable(Test-zoneDistribute ${_FILES})
target_compile_features(Test-zoneDistribute PUBLIC cxx_std_11)
target_link_libraries(Test-zoneDistribute PUBLIC finiteVolume)
