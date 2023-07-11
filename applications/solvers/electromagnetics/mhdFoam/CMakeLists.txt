set(_FILES
  mhdFoam.C
)
add_executable(mhdFoam ${_FILES})
target_compile_features(mhdFoam PUBLIC cxx_std_11)
target_link_libraries(mhdFoam PUBLIC finiteVolume)
