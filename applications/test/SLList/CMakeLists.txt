set(_FILES
  Test-SLList.C
)
add_executable(Test-SLList ${_FILES})
target_compile_features(Test-SLList PUBLIC cxx_std_11)
target_link_libraries(Test-SLList PUBLIC finiteVolume)
