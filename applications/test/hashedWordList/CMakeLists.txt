set(_FILES
  Test-hashedWordList.C
)
add_executable(Test-hashedWordList ${_FILES})
target_compile_features(Test-hashedWordList PUBLIC cxx_std_11)
target_link_libraries(Test-hashedWordList PUBLIC finiteVolume)
