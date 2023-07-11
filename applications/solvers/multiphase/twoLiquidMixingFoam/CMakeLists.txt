set(_FILES
  twoLiquidMixingFoam.C
)
add_executable(twoLiquidMixingFoam ${_FILES})
target_compile_features(twoLiquidMixingFoam PUBLIC cxx_std_11)
target_link_libraries(twoLiquidMixingFoam PUBLIC finiteVolume)
