set(_FILES
  clouds/baseClasses/sprayCloud/sprayCloud.C
  parcels/derived/basicSprayParcel/defineBasicSprayParcel.C
  parcels/derived/basicSprayParcel/makeBasicSprayParcelSubmodels.C
)
add_library(lagrangianSpray ${_FILES})
target_compile_features(lagrangianSpray PUBLIC cxx_std_11)
target_include_directories(lagrangianSpray PUBLIC include
  PRIVATE
    includePrivate
    clouds/Templates/SprayCloud
    parcels/Templates/SprayParcel
    submodels/AtomizationModel/AtomizationModel
    submodels/AtomizationModel/BlobsSheetAtomization
    submodels/AtomizationModel/LISAAtomization
    submodels/AtomizationModel/NoAtomization
    submodels/BreakupModel/BreakupModel
    submodels/BreakupModel/ETAB
    submodels/BreakupModel/NoBreakup
    submodels/BreakupModel/PilchErdman
    submodels/BreakupModel/ReitzDiwakar
    submodels/BreakupModel/ReitzKHRT
    submodels/BreakupModel/SHF
    submodels/BreakupModel/TAB
    submodels/StochasticCollision/ORourkeCollision
    submodels/StochasticCollision/TrajectoryCollision
)
target_link_libraries(lagrangianSpray PUBLIC lagrangianTurbulence finiteVolume)
