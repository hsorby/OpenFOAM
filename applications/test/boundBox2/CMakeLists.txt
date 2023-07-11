set(_FILES
  Test-boundBox2.C
)
add_executable(Test-boundBox2 ${_FILES})
target_compile_features(Test-boundBox2 PUBLIC cxx_std_11)
target_link_libraries(Test-boundBox2 PUBLIC finiteVolume)
