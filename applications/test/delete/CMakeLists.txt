set(_FILES
  Test-delete.C
)
add_executable(Test-delete ${_FILES})
target_compile_features(Test-delete PUBLIC cxx_std_11)
target_link_libraries(Test-delete PUBLIC finiteVolume)
