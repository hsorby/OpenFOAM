set(_FILES
  Test-fieldDependency.C
)
add_executable(Test-fieldDependency ${_FILES})
target_compile_features(Test-fieldDependency PUBLIC cxx_std_11)
target_link_libraries(Test-fieldDependency PUBLIC finiteVolume)
