set(_FILES
  compressibleTurbulenceModel.C
  turbulentFluidThermoModels/turbulentFluidThermoModels.C
)
add_library(compressibleTurbulenceModels ${_FILES})
target_compile_features(compressibleTurbulenceModels PUBLIC cxx_std_11)
target_include_directories(compressibleTurbulenceModels
  PUBLIC
    include
    includePrivate
    CompressibleTurbulenceModel
    EddyDiffusivity
    RAS/buoyantKEpsilon
    ThermalDiffusivity
    turbulentFluidThermoModels
)
target_link_libraries(compressibleTurbulenceModels PUBLIC turbulenceModels compressibleTransportModels radiationModels)
