set(_FILES
  magneticFoam.C
)
add_executable(magneticFoam ${_FILES})
target_compile_features(magneticFoam PUBLIC cxx_std_11)
target_link_libraries(magneticFoam PUBLIC finiteVolume)
