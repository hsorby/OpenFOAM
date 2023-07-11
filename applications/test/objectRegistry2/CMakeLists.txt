set(_FILES
  Test-objectRegistry2.C
)
add_executable(Test-objectRegistry2 ${_FILES})
target_compile_features(Test-objectRegistry2 PUBLIC cxx_std_11)
target_link_libraries(Test-objectRegistry2 PUBLIC finiteVolume)
