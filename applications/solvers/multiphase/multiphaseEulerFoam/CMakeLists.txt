set(_FILES
  multiphaseEulerFoam.C
)
add_executable(multiphaseEulerFoam ${_FILES})
target_compile_features(multiphaseEulerFoam PUBLIC cxx_std_11)
target_link_libraries(multiphaseEulerFoam PUBLIC finiteVolume)
