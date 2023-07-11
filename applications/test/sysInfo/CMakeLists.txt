set(_FILES
  Test-sysInfo.C
)
add_executable(Test-sysInfo ${_FILES})
target_compile_features(Test-sysInfo PUBLIC cxx_std_11)
target_link_libraries(Test-sysInfo PUBLIC finiteVolume)
