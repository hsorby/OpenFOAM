set(_FILES
  Test-fieldTypes.C
)
add_executable(Test-fieldTypes ${_FILES})
target_compile_features(Test-fieldTypes PUBLIC cxx_std_11)
target_link_libraries(Test-fieldTypes PUBLIC finiteVolume)
