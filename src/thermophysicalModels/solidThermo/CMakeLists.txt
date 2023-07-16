set(_FILES
  solidThermo/solidThermo.C
  solidThermo/solidThermos.C
  solidReactionThermo/solidReactionThermo.C
  solidReactionThermo/solidReactionThermos.C
  solidThermo/heZoneSolidThermos.C
)
add_library(solidThermo ${_FILES})
target_compile_features(solidThermo PUBLIC cxx_std_11)
target_include_directories(solidThermo PUBLIC include includePrivate solidThermo)
target_link_libraries(solidThermo PUBLIC finiteVolume fluidThermophysicalModels reactionThermophysicalModels)
