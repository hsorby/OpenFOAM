set(_FILES
  Test-memInfo.C
)
add_executable(Test-memInfo ${_FILES})
target_compile_features(Test-memInfo PUBLIC cxx_std_11)
target_link_libraries(Test-memInfo PUBLIC finiteVolume)
