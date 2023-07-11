set(_FILES
  Test-broadcastCopy.C
)
add_executable(Test-broadcastCopy ${_FILES})
target_compile_features(Test-broadcastCopy PUBLIC cxx_std_11)
target_link_libraries(Test-broadcastCopy PUBLIC finiteVolume)
