set(_FILES
  SLGThermo/SLGThermo.C
)
add_library(SLGThermo ${_FILES})
target_compile_features(SLGThermo PUBLIC cxx_std_11)
target_include_directories(SLGThermo PUBLIC include includePrivate)
target_link_libraries(SLGThermo PUBLIC finiteVolume fluidThermophysicalModels reactionThermophysicalModels)
