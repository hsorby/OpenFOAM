set(_FILES
  Test-findTimes.C
)
add_executable(Test-findTimes ${_FILES})
target_compile_features(Test-findTimes PUBLIC cxx_std_11)
target_link_libraries(Test-findTimes PUBLIC finiteVolume)
