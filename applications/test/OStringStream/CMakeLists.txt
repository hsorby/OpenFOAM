set(_FILES
  Test-OStringStream.C
)
add_executable(Test-OStringStream ${_FILES})
target_compile_features(Test-OStringStream PUBLIC cxx_std_11)
target_link_libraries(Test-OStringStream PUBLIC finiteVolume)
