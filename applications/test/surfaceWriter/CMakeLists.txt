set(_FILES
  Test-surfaceWriter.C
)
add_executable(Test-surfaceWriter ${_FILES})
target_compile_features(Test-surfaceWriter PUBLIC cxx_std_11)
target_link_libraries(Test-surfaceWriter PUBLIC finiteVolume)
