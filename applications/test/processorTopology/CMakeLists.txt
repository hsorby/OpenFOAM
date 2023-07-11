set(_FILES
  Test-processorTopology.C
)
add_executable(Test-processorTopology ${_FILES})
target_compile_features(Test-processorTopology PUBLIC cxx_std_11)
target_link_libraries(Test-processorTopology PUBLIC finiteVolume)
