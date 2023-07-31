set(_FILES
  parcels/derived/basicKinematicParcel/makeBasicKinematicParcelSubmodels.C
  parcels/derived/basicKinematicCollidingParcel/makeBasicKinematicCollidingParcelSubmodels.C
  parcels/derived/basicThermoParcel/makeBasicThermoParcelSubmodels.C
  parcels/derived/basicReactingParcel/makeBasicReactingParcelSubmodels.C
  parcels/derived/basicReactingMultiphaseParcel/makeBasicReactingMultiphaseParcelSubmodels.C
  parcels/derived/basicKinematicMPPICParcel/makeBasicKinematicMPPICParcelSubmodels.C
  parcels/derived/basicHeterogeneousReactingParcel/makeBasicHeterogeneousParcelSubmodels.C
)
add_library(lagrangianTurbulence ${_FILES})
target_compile_features(lagrangianTurbulence PUBLIC cxx_std_11)
target_include_directories(lagrangianTurbulence PUBLIC include
    includePrivate
    submodels/Kinematic/DispersionModel/DispersionRASModel
    submodels/Kinematic/DispersionModel/GradientDispersionRAS
    submodels/Kinematic/DispersionModel/StochasticDispersionRAS
    submodels/Thermodynamic/ParticleForces/BrownianMotion
)
target_link_libraries(lagrangianTurbulence PUBLIC lagrangianIntermediate)
