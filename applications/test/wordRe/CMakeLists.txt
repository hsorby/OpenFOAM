set(_FILES
  Test-wordRe.C
)
add_executable(Test-wordRe ${_FILES})
target_compile_features(Test-wordRe PUBLIC cxx_std_11)
target_link_libraries(Test-wordRe PUBLIC finiteVolume)
