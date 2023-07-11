set(_FILES
  Test-foamEnv.C
)
add_executable(Test-foamEnv ${_FILES})
target_compile_features(Test-foamEnv PUBLIC cxx_std_11)
target_link_libraries(Test-foamEnv PUBLIC finiteVolume)
