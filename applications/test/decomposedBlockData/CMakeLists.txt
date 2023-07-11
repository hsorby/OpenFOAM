set(_FILES
  Test-decomposedBlockData.C
)
add_executable(Test-decomposedBlockData ${_FILES})
target_compile_features(Test-decomposedBlockData PUBLIC cxx_std_11)
target_link_libraries(Test-decomposedBlockData PUBLIC finiteVolume)
