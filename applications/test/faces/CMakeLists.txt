set(_FILES
  Test-faces.C
)
add_executable(Test-faces ${_FILES})
target_compile_features(Test-faces PUBLIC cxx_std_11)
target_link_libraries(Test-faces PUBLIC finiteVolume)
