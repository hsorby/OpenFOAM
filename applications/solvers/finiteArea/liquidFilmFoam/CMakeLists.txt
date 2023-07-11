set(_FILES
  liquidFilmFoam.C
)
add_executable(liquidFilmFoam ${_FILES})
target_compile_features(liquidFilmFoam PUBLIC cxx_std_11)
target_link_libraries(liquidFilmFoam PUBLIC finiteVolume)
