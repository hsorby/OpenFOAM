set(_FILES
  thermalBaffleModel/thermalBaffleModel.C
  thermalBaffleModel/thermalBaffleModelNew.C
  thermalBaffle/thermalBaffle.C
  noThermo/noThermo.C
  derivedFvPatchFields/thermalBaffle/thermalBaffleFvPatchScalarField.C
)
add_library(thermalBaffleModels ${_FILES})
target_compile_features(thermalBaffleModels PUBLIC cxx_std_11)
target_include_directories(thermalBaffleModels PUBLIC include PRIVATE includePrivate)
target_link_libraries(thermalBaffleModels PUBLIC regionModels radiationModels compressibleTurbulenceModels thermoTools)
