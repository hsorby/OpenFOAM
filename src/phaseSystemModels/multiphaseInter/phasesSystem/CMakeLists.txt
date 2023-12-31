set(_FILES
  phaseModel/phaseModel/phaseModel.C
  phaseModel/phaseModel/phaseModels.C
  phasePair/phasePair.C
  phasePair/phasePairKey.C
  phasePair/orderedPhasePair.C
  multiphaseInterSystem/multiphaseInterSystem.C
  multiphaseSystem/multiphaseSystem.C
  multiphaseSystem/multiphaseSystemNew.C
  multiphaseSystem/multiphaseSystems.C
  interfaceCompositionModelCamel/interfaceCompositionModel.C
  InterfaceCompositionModel/InterfaceCompositionModels.C
  interfaceModels/porousModels/porousModel/porousModel.C
  interfaceModels/porousModels/VollerPrakash/VollerPrakash.C
  interfaceModels/surfaceTensionModels/surfaceTensionModel/surfaceTensionModel.C
  interfaceModels/surfaceTensionModels/constantSurfaceTensionCoefficient/constantSurfaceTensionCoefficient.C
  derivedFvPatchFields/timeVaryingMassSorption/timeVaryingMassSorptionFvPatchScalarField.C
)
add_library(incompressibleMultiphaseSystems ${_FILES})
target_compile_features(incompressibleMultiphaseSystems PUBLIC cxx_std_11)
target_include_directories(incompressibleMultiphaseSystems
  PUBLIC
    include
    includePrivate
    InterfaceCompositionModel
    MassTransferPhaseSystem
    massTransferModels/Lee
    massTransferModels/diffusionGasEvaporation
    massTransferModels/interfaceHeatResistance
    massTransferModels/interfaceOxideRate
    massTransferModels/kineticGasEvaporation
    phaseModel/MovingPhaseModel
    phaseModel/MultiComponentPhaseModel
    phaseModel/PurePhaseModel
    phaseModel/StaticPhaseModel
)
target_link_libraries(incompressibleMultiphaseSystems PUBLIC finiteVolume incompressibleTransportModels compressibleTransportModels fluidThermophysicalModels compressibleTurbulenceModels geometricVoF saturationModel)
