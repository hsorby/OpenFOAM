set(_FILES
  cellCuts/cutCell/cutCell.C
  cellCuts/cutCell/cutCellPLIC.C
  cellCuts/cutCell/cutCellIso.C
  cellCuts/cutFace/cutFace.C
  cellCuts/cutFace/cutFacePLIC.C
  cellCuts/cutFace/cutFaceAdvect.C
  cellCuts/cutFace/cutFaceIso.C
  surfaceIterators/surfaceIteratorPLIC.C
  surfaceIterators/surfaceIteratorIso.C
  reconstructedDistanceFunction/reconstructedDistanceFunction.C
  reconstructionSchemes/reconstructionSchemesNew.C
  reconstructionSchemes/reconstructionSchemes.C
  reconstructionSchemes/isoSchemes/isoAlpha/isoAlpha.C
  reconstructionSchemes/plicSchemes/gradAlpha/gradAlpha.C
  reconstructionSchemes/plicSchemes/plicRDF/plicRDF.C
  advectionSchemes/isoAdvection/isoAdvection.C
  sampledInterface/sampledInterface.C
)
add_library(geometricVoF ${_FILES})
target_compile_features(geometricVoF PUBLIC cxx_std_11)
target_include_directories(geometricVoF PUBLIC include PRIVATE includePrivate)
