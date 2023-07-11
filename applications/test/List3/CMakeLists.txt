set(_FILES
  Test-List3.C
)
add_executable(Test-List3 ${_FILES})
target_compile_features(Test-List3 PUBLIC cxx_std_11)
target_link_libraries(Test-List3 PUBLIC finiteVolume)
