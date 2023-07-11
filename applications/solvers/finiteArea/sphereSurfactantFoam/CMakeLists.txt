set(_FILES
  sphereSurfactantFoam.C
)
add_executable(sphereSurfactantFoam ${_FILES})
target_compile_features(sphereSurfactantFoam PUBLIC cxx_std_11)
target_link_libraries(sphereSurfactantFoam PUBLIC finiteVolume)
