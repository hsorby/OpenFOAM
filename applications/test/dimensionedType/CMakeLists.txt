set(_FILES
  Test-dimensionedType.C
)
add_executable(Test-dimensionedType ${_FILES})
target_compile_features(Test-dimensionedType PUBLIC cxx_std_11)
target_link_libraries(Test-dimensionedType PUBLIC finiteVolume)
