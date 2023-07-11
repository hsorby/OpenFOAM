set(_FILES
  Test-DirLister.C
  DirLister.C
)
add_executable(Test-DirLister ${_FILES})
target_compile_features(Test-DirLister PUBLIC cxx_std_11)
target_link_libraries(Test-DirLister PUBLIC finiteVolume)
