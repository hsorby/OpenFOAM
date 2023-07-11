set(_FILES
  tractionDisplacement/tractionDisplacementFvPatchVectorField.C
  solidDisplacementFoam.C
)
add_executable(solidDisplacementFoam ${_FILES})
target_compile_features(solidDisplacementFoam PUBLIC cxx_std_11)
target_link_libraries(solidDisplacementFoam PUBLIC finiteVolume)
