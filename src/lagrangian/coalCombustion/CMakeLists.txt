set(_FILES
  coalParcel/makeCoalParcelSubmodels.C
  coalCloudList/coalCloudList.C
)
add_library(coalCombustion ${_FILES})
target_compile_features(coalCombustion PUBLIC cxx_std_11)
target_include_directories(coalCombustion PUBLIC include
  PRIVATE
    includePrivate
    submodels/surfaceReactionModel/COxidationDiffusionLimitedRate
    submodels/surfaceReactionModel/COxidationHurtMitchell
    submodels/surfaceReactionModel/COxidationIntrinsicRate
    submodels/surfaceReactionModel/COxidationKineticDiffusionLimitedRate
    submodels/surfaceReactionModel/COxidationMurphyShaddix
)
target_link_libraries(coalCombustion PUBLIC lagrangianIntermediate)
