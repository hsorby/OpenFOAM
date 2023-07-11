set(_FILES
  Test-readDir.C
)
add_executable(Test-readDir ${_FILES})
target_compile_features(Test-readDir PUBLIC cxx_std_11)
target_link_libraries(Test-readDir PUBLIC finiteVolume)
