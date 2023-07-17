set(_FILES
  twoPhaseSystem.C
  twoPhaseSystemNew.C
  twoPhaseSystems.C
  diameterModels/IATE/IATE.C
  diameterModels/IATE/IATEsources/IATEsource/IATEsource.C
  diameterModels/IATE/IATEsources/wakeEntrainmentCoalescence/wakeEntrainmentCoalescence.C
  diameterModels/IATE/IATEsources/turbulentBreakUp/turbulentBreakUp.C
  diameterModels/IATE/IATEsources/randomCoalescence/randomCoalescence.C
  diameterModels/IATE/IATEsources/phaseChange/phaseChange.C
  diameterModels/IATE/IATEsources/wallBoiling/wallBoiling.C
)
add_library(reactingTwoPhaseSystem ${_FILES})
target_compile_features(reactingTwoPhaseSystem PUBLIC cxx_std_11)
target_include_directories(reactingTwoPhaseSystem PUBLIC include PRIVATE includePrivate)
target_link_libraries(reactingTwoPhaseSystem PUBLIC finiteVolume reactingMultiphaseSystem compressibleTwoPhaseSystem)
