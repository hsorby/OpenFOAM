set(_FILES
  Test-predicates.C
)
add_executable(Test-predicates ${_FILES})
target_compile_features(Test-predicates PUBLIC cxx_std_11)
target_link_libraries(Test-predicates PUBLIC finiteVolume)
