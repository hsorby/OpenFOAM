set(_FILES
  surfactantFoam.C
)
add_executable(surfactantFoam ${_FILES})
target_compile_features(surfactantFoam PUBLIC cxx_std_11)
target_link_libraries(surfactantFoam PUBLIC finiteVolume)
