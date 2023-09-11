set(_FILES
  hexBlock.C
  plot3dToFoam.C
)
add_executable(plot3dToFoam ${_FILES})
target_compile_features(plot3dToFoam PUBLIC cxx_std_11)
target_link_libraries(plot3dToFoam PUBLIC meshTools)
