set(_FILES
  Test-pTraits.C
)
add_executable(Test-pTraits ${_FILES})
target_compile_features(Test-pTraits PUBLIC cxx_std_11)
target_link_libraries(Test-pTraits PUBLIC finiteVolume)
