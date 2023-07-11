set(_FILES
  Test-vtmWriter.C
)
add_executable(Test-vtmWriter ${_FILES})
target_compile_features(Test-vtmWriter PUBLIC cxx_std_11)
target_link_libraries(Test-vtmWriter PUBLIC finiteVolume)
