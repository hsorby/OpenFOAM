set(_FILES
  electrostaticFoam.C
)
add_executable(electrostaticFoam ${_FILES})
target_compile_features(electrostaticFoam PUBLIC cxx_std_11)
target_link_libraries(electrostaticFoam PUBLIC finiteVolume)
