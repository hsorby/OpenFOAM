set(_FILES
  Test-mvBak.C
)
add_executable(Test-mvBak ${_FILES})
target_compile_features(Test-mvBak PUBLIC cxx_std_11)
target_link_libraries(Test-mvBak PUBLIC finiteVolume)
