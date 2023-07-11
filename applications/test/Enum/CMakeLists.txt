set(_FILES
  Test-Enum.C
)
add_executable(Test-Enum ${_FILES})
target_compile_features(Test-Enum PUBLIC cxx_std_11)
target_link_libraries(Test-Enum PUBLIC finiteVolume)
