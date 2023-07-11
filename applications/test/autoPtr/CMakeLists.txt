set(_FILES
  Test-autoPtr.C
)
add_executable(Test-autoPtr ${_FILES})
target_compile_features(Test-autoPtr PUBLIC cxx_std_11)
target_link_libraries(Test-autoPtr PUBLIC finiteVolume)
