set(_FILES
  Test-cpuInfo.C
)
add_executable(Test-cpuInfo ${_FILES})
target_compile_features(Test-cpuInfo PUBLIC cxx_std_11)
target_link_libraries(Test-cpuInfo PUBLIC finiteVolume)
