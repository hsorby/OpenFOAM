set(_FILES
  laplacianDyMFoam.C
)
add_executable(correctBoundaryConditions ${_FILES})
target_compile_features(correctBoundaryConditions PUBLIC cxx_std_11)
target_link_libraries(correctBoundaryConditions PUBLIC finiteVolume)
