set(_FILES
  Test-graphXi.C
)
add_executable(Test-graphXi ${_FILES})
target_compile_features(Test-graphXi PUBLIC cxx_std_11)
target_link_libraries(Test-graphXi PUBLIC finiteVolume)
