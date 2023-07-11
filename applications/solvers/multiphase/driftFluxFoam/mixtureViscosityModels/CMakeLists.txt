set(_FILES
  mixtureViscosityModel/mixtureViscosityModel.C
  mixtureViscosityModel/mixtureViscosityModelNew.C
  plastic/plastic.C
  BinghamPlastic/BinghamPlastic.C
  slurry/slurry.C
)
add_library(driftFluxTransportModels ${_FILES})
target_compile_features(driftFluxTransportModels PUBLIC cxx_std_11)
target_include_directories(driftFluxTransportModels PUBLIC include PRIVATE includePrivate)
