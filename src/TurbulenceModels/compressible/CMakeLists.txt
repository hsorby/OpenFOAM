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
    ${OPENFOAM_SRC_DIR}/TurbulenceModels/phaseCompressible/PhaseCompressibleTurbulenceModel
    ${OPENFOAM_SRC_DIR}/TurbulenceModels/phaseCompressible/RAS/kOmegaSSTSato
    ${OPENFOAM_SRC_DIR}/TurbulenceModels/phaseCompressible/RAS/mixtureKEpsilon
    ${OPENFOAM_SRC_DIR}/TurbulenceModels/phaseCompressible/RAS/LaheyKEpsilon
    ${OPENFOAM_SRC_DIR}/TurbulenceModels/phaseCompressible/RAS/continuousGasKEpsilon
    ${OPENFOAM_SRC_DIR}/TurbulenceModels/phaseCompressible/LES/Niceno
    ${OPENFOAM_SRC_DIR}/TurbulenceModels/phaseCompressible/LES/SmagorinskyZhang
    ${OPENFOAM_SRC_DIR}/TurbulenceModels/phaseCompressible/LES/continuousGasKEqn
)
target_link_libraries(compressibleTurbulenceModels PUBLIC turbulenceModels compressibleTransportModels radiationModels)
