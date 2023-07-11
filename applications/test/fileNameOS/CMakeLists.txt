set(_FILES
  Test-fileNameOS.C
)
add_executable(Test-fileNameOS ${_FILES})
target_compile_features(Test-fileNameOS PUBLIC cxx_std_11)
target_link_libraries(Test-fileNameOS PUBLIC finiteVolume)
