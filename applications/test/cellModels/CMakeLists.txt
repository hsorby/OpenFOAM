set(_FILES
  Test-cellModels.C
)
add_executable(Test-cellModels ${_FILES})
target_compile_features(Test-cellModels PUBLIC cxx_std_11)
target_link_libraries(Test-cellModels PUBLIC finiteVolume)
