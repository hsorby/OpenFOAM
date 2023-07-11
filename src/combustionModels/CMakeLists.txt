set(_FILES
  combustionModel/combustionModel.C
  CombustionModel/CombustionModel/CombustionModels.C
  diffusion/diffusions.C
  infinitelyFastChemistry/infinitelyFastChemistrys.C
  PaSR/PaSRs.C
  EDC/EDCs.C
  eddyDissipationDiffusionModel/eddyDissipationDiffusionModels.C
  laminar/laminars.C
  FSD/reactionRateFlameAreaModels/consumptionSpeed/consumptionSpeed.C
  FSD/reactionRateFlameAreaModels/reactionRateFlameArea/reactionRateFlameArea.C
  FSD/reactionRateFlameAreaModels/reactionRateFlameArea/reactionRateFlameAreaNew.C
  FSD/reactionRateFlameAreaModels/relaxation/relaxation.C
  FSD/FSDs.C
  diffusionMulticomponent/diffusionMulticomponents.C
  zoneCombustion/zoneCombustions.C
  noCombustion/noCombustions.C
)
add_library(combustionModels ${_FILES})
target_compile_features(combustionModels PUBLIC cxx_std_11)
target_include_directories(combustionModels PUBLIC include PRIVATE includePrivate)
