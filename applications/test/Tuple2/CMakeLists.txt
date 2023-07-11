set(_FILES
  Test-Tuple2.C
)
add_executable(Test-Tuple2 ${_FILES})
target_compile_features(Test-Tuple2 PUBLIC cxx_std_11)
target_link_libraries(Test-Tuple2 PUBLIC finiteVolume)
