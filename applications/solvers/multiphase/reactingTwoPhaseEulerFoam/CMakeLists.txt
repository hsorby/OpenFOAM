set(_FILES
  reactingTwoPhaseEulerFoam.C
)
add_executable(reactingTwoPhaseEulerFoam ${_FILES})
target_compile_features(reactingTwoPhaseEulerFoam PUBLIC cxx_std_11)
target_link_libraries(reactingTwoPhaseEulerFoam PUBLIC finiteVolume)
