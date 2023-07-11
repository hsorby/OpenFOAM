set(_FILES
  Test-fvSolutionCombine.C
)
add_executable(Test-fvSolutionCombine ${_FILES})
target_compile_features(Test-fvSolutionCombine PUBLIC cxx_std_11)
target_link_libraries(Test-fvSolutionCombine PUBLIC finiteVolume)
