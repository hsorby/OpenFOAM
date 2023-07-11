set(_FILES
  Test-contiguous.C
)
add_executable(Test-contiguous ${_FILES})
target_compile_features(Test-contiguous PUBLIC cxx_std_11)
target_link_libraries(Test-contiguous PUBLIC finiteVolume)
