set(_FILES
  Test-nullObject.C
)
add_executable(Test-nullObject ${_FILES})
target_compile_features(Test-nullObject PUBLIC cxx_std_11)
target_link_libraries(Test-nullObject PUBLIC finiteVolume)
