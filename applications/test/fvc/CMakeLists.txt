set(_FILES
  Test-fvc.C
)
add_executable(Test-fvc ${_FILES})
target_compile_features(Test-fvc PUBLIC cxx_std_11)
target_link_libraries(Test-fvc PUBLIC finiteVolume)
