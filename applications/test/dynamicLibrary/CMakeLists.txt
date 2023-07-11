set(_FILES
  Test-dynamicLibrary.C
)
add_executable(Test-dynamicLibrary ${_FILES})
target_compile_features(Test-dynamicLibrary PUBLIC cxx_std_11)
target_link_libraries(Test-dynamicLibrary PUBLIC finiteVolume)
