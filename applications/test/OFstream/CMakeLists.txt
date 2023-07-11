set(_FILES
  Test-OFstream.C
)
add_executable(Test-OFstream ${_FILES})
target_compile_features(Test-OFstream PUBLIC cxx_std_11)
target_link_libraries(Test-OFstream PUBLIC finiteVolume)
