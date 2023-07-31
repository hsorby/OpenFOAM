set(_FILES
  parcels/derived/dsmcParcel/dsmcParcel.C
  clouds/baseClasses/DSMCBaseCloud/DSMCBaseCloud.C
  parcels/derived/dsmcParcel/defineDSMCParcel.C
  parcels/derived/dsmcParcel/makeDSMCParcelBinaryCollisionModels.C
  parcels/derived/dsmcParcel/makeDSMCParcelWallInteractionModels.C
  parcels/derived/dsmcParcel/makeDSMCParcelInflowBoundaryModels.C
)
add_library(DSMC ${_FILES})
target_compile_features(DSMC PUBLIC cxx_std_11)
target_include_directories(DSMC
  PUBLIC
    include
    includePrivate
    clouds/Templates/DSMCCloud
    parcels/Templates/DSMCParcel
    submodels/BinaryCollisionModel/BinaryCollisionModel
    submodels/BinaryCollisionModel/LarsenBorgnakkeVariableHardSphere
    submodels/BinaryCollisionModel/NoBinaryCollision
    submodels/BinaryCollisionModel/VariableHardSphere
    submodels/InflowBoundaryModel/FreeStream
    submodels/InflowBoundaryModel/InflowBoundaryModel
    submodels/InflowBoundaryModel/NoInflow
    submodels/WallInteractionModel/MaxwellianThermal
    submodels/WallInteractionModel/MixedDiffuseSpecular
    submodels/WallInteractionModel/SpecularReflection
    submodels/WallInteractionModel/WallInteractionModel
)
target_link_libraries(DSMC PUBLIC lagrangian finiteVolume)
