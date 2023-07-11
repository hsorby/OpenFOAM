set(_FILES
  Test-wallDistDyM.C
)
add_executable(Test-wallDistDyM ${_FILES})
target_compile_features(Test-wallDistDyM PUBLIC cxx_std_11)
target_link_libraries(Test-wallDistDyM PUBLIC finiteVolume)
