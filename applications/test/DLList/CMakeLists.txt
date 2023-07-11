set(_FILES
  Test-DLList.C
)
add_executable(Test-DLList ${_FILES})
target_compile_features(Test-DLList PUBLIC cxx_std_11)
target_link_libraries(Test-DLList PUBLIC finiteVolume)
