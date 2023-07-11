set(_FILES
  multiphaseInterFoam.C
)
add_executable(multiphaseInterFoam ${_FILES})
target_compile_features(multiphaseInterFoam PUBLIC cxx_std_11)
target_link_libraries(multiphaseInterFoam PUBLIC finiteVolume)
