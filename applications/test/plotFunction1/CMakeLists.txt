set(_FILES
  Test-plotFunction1.C
)
add_executable(Test-plotFunction1 ${_FILES})
target_compile_features(Test-plotFunction1 PUBLIC cxx_std_11)
target_link_libraries(Test-plotFunction1 PUBLIC finiteVolume)
