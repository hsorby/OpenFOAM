set(_FILES
  Test-etcFiles.C
)
add_executable(Test-etcFiles ${_FILES})
target_compile_features(Test-etcFiles PUBLIC cxx_std_11)
target_link_libraries(Test-etcFiles PUBLIC finiteVolume)
