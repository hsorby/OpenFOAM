set(_FILES
  incompressibleTurbulenceModel.C
  incompressibleRhoTurbulenceModel.C
  turbulentTransportModels/turbulentTransportModels.C
  turbulentTransportModels/RAS/qZeta/qZeta.C
  turbulentTransportModels/RAS/kkLOmega/kkLOmega.C
  turbulentTransportModels/RAS/LamBremhorstKE/LamBremhorstKE.C
  turbulentTransportModels/RAS/LienLeschziner/LienLeschziner.C
  turbulentTransportModels/RAS/ShihQuadraticKE/ShihQuadraticKE.C
  turbulentTransportModels/RAS/LienCubicKE/LienCubicKE.C
  turbulentTransportModels/derivedFvPatchFields/wallFunctions/alphatWallFunctions/alphatJayatillekeWallFunction/alphatJayatillekeWallFunctionFvPatchScalarField.C
)
add_library(incompressibleTurbulenceModels ${_FILES})
target_compile_features(incompressibleTurbulenceModels PUBLIC cxx_std_11)
target_include_directories(incompressibleTurbulenceModels
  PUBLIC
    include
    includePrivate
    IncompressibleTurbulenceModel
    turbulentTransportModels
    ${OPENFOAM_SRC_DIR}/TurbulenceModels/phaseIncompressible/PhaseIncompressibleTurbulenceModel
)
target_link_libraries(incompressibleTurbulenceModels PUBLIC turbulenceModels incompressibleTransportModels)
