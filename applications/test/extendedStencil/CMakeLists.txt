set(_FILES
  Test-ExtendedStencil.C
)
add_executable(Test-ExtendedStencil ${_FILES})
target_compile_features(Test-ExtendedStencil PUBLIC cxx_std_11)
target_link_libraries(Test-ExtendedStencil PUBLIC finiteVolume)
