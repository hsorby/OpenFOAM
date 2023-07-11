set(_FILES
  Test-ITstream.C
)
add_executable(Test-ITstream ${_FILES})
target_compile_features(Test-ITstream PUBLIC cxx_std_11)
target_link_libraries(Test-ITstream PUBLIC finiteVolume)
