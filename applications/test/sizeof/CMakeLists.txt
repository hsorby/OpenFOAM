set(_FILES
  Test-sizeof.C
)
add_executable(Test-sizeof ${_FILES})
target_compile_features(Test-sizeof PUBLIC cxx_std_11)
target_link_libraries(Test-sizeof PUBLIC finiteVolume)
