set(_FILES
  Test-List.C
)
add_executable(Test-List ${_FILES})
target_compile_features(Test-List PUBLIC cxx_std_11)
target_link_libraries(Test-List PUBLIC finiteVolume)
