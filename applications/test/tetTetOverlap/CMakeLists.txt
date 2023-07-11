set(_FILES
  Test-tetTetOverlap.C
)
add_executable(Test-tetTetOverlap ${_FILES})
target_compile_features(Test-tetTetOverlap PUBLIC cxx_std_11)
target_link_libraries(Test-tetTetOverlap PUBLIC finiteVolume)
