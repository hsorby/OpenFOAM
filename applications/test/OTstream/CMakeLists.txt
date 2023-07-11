set(_FILES
  Test-OTstream.C
)
add_executable(Test-OTstream ${_FILES})
target_compile_features(Test-OTstream PUBLIC cxx_std_11)
target_link_libraries(Test-OTstream PUBLIC finiteVolume)
