set(_FILES
  viscosityModels/viscosityModel/viscosityModel.C
  viscosityModels/viscosityModel/viscosityModelNew.C
  viscosityModels/Newtonian/Newtonian.C
  viscosityModels/powerLaw/powerLaw.C
  viscosityModels/CrossPowerLaw/CrossPowerLaw.C
  viscosityModels/BirdCarreau/BirdCarreau.C
  viscosityModels/HerschelBulkley/HerschelBulkley.C
  viscosityModels/Casson/Casson.C
  viscosityModels/strainRateFunction/strainRateFunction.C
  viscosityModels/Arrhenius/Arrheniuss.C
  transportModel/transportModel.C
  singlePhaseTransportModel/singlePhaseTransportModel.C
  incompressibleTwoPhaseMixture/incompressibleTwoPhaseMixture.C
)
add_library(incompressibleTransportModels ${_FILES})
target_compile_features(incompressibleTransportModels PUBLIC cxx_std_11)
target_include_directories(incompressibleTransportModels PUBLIC include includePrivate viscosityModels/Arrhenius)
target_link_libraries(incompressibleTransportModels PUBLIC finiteVolume twoPhaseMixture)
