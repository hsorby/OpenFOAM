set(_FILES
  Test-boundBox.C
)
add_executable(Test-boundBox ${_FILES})
target_compile_features(Test-boundBox PUBLIC cxx_std_11)
target_link_libraries(Test-boundBox PUBLIC finiteVolume)
