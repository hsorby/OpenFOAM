set(_FILES
  Test-timeSelector.C
)
add_executable(Test-timeSelector ${_FILES})
target_compile_features(Test-timeSelector PUBLIC cxx_std_11)
target_link_libraries(Test-timeSelector PUBLIC finiteVolume)
