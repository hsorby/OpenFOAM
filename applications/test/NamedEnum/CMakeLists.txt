set(_FILES
  Test-NamedEnum.C
)
add_executable(Test-NamedEnum ${_FILES})
target_compile_features(Test-NamedEnum PUBLIC cxx_std_11)
target_link_libraries(Test-NamedEnum PUBLIC finiteVolume)
