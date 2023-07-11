set(_FILES
  Test-surfaceReading.C
)
add_executable(Test-surfaceReading ${_FILES})
target_compile_features(Test-surfaceReading PUBLIC cxx_std_11)
target_link_libraries(Test-surfaceReading PUBLIC finiteVolume)
