set(_FILES
  acousticFoam.C
)
add_executable(acousticFoam ${_FILES})
target_compile_features(acousticFoam PUBLIC cxx_std_11)
target_link_libraries(acousticFoam PUBLIC finiteVolume)
