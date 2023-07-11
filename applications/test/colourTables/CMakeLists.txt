set(_FILES
  Test-colourTables.C
)
add_executable(Test-colourTables ${_FILES})
target_compile_features(Test-colourTables PUBLIC cxx_std_11)
target_link_libraries(Test-colourTables PUBLIC finiteVolume)
