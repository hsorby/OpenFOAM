set(_FILES
  Test-instant.C
)
add_executable(Test-instant ${_FILES})
target_compile_features(Test-instant PUBLIC cxx_std_11)
target_link_libraries(Test-instant PUBLIC finiteVolume)
