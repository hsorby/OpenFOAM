set(_FILES
  Test-vectorSpeed.C
)
add_executable(Test-vectorSpeed ${_FILES})
target_compile_features(Test-vectorSpeed PUBLIC cxx_std_11)
target_link_libraries(Test-vectorSpeed PUBLIC finiteVolume)
