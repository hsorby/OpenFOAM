set(_FILES
  Test-scalarSpeed.C
)
add_executable(Test-scalarSpeed ${_FILES})
target_compile_features(Test-scalarSpeed PUBLIC cxx_std_11)
target_link_libraries(Test-scalarSpeed PUBLIC finiteVolume)
