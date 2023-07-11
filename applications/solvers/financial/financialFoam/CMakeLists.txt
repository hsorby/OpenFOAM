set(_FILES
  financialFoam.C
)
add_executable(financialFoam ${_FILES})
target_compile_features(financialFoam PUBLIC cxx_std_11)
target_link_libraries(financialFoam PUBLIC finiteVolume)
