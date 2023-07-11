set(_FILES
  Test-dictionaryCopy.C
)
add_executable(Test-dictionaryCopy ${_FILES})
target_compile_features(Test-dictionaryCopy PUBLIC cxx_std_11)
target_link_libraries(Test-dictionaryCopy PUBLIC finiteVolume)
