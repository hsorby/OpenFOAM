set(_FILES
  Test-fileNameClean.C
)
add_executable(Test-fileNameClean ${_FILES})
target_compile_features(Test-fileNameClean PUBLIC cxx_std_11)
target_link_libraries(Test-fileNameClean PUBLIC finiteVolume)
