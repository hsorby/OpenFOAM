set(_FILES
  decompositionMethod/decompositionMethod.C
  geomDecomp/geomDecomp.C
  simpleGeomDecomp/simpleGeomDecomp.C
  hierarchGeomDecomp/hierarchGeomDecomp.C
  manualDecomp/manualDecomp.C
  multiLevelDecomp/multiLevelDecomp.C
  metisLikeDecomp/metisLikeDecomp.C
  structuredDecomp/structuredDecomp.C
  randomDecomp/randomDecomp.C
  noDecomp/noDecomp.C
  decompositionConstraints/decompositionConstraint/decompositionConstraint.C
  decompositionConstraints/preserveBaffles/preserveBafflesConstraint.C
  decompositionConstraints/preserveFaceZones/preserveFaceZonesConstraint.C
  decompositionConstraints/preservePatches/preservePatchesConstraint.C
  decompositionConstraints/geometric/geometricConstraint.C
  decompositionConstraints/singleProcessorFaceSets/singleProcessorFaceSetsConstraint.C
  decompositionConstraints/refinementHistory/refinementHistoryConstraint.C
)
add_library(decompositionMethods ${_FILES})
target_compile_features(decompositionMethods PUBLIC cxx_std_11)
target_include_directories(decompositionMethods PUBLIC include PRIVATE includePrivate)
target_link_libraries(decompositionMethods PUBLIC meshTools finiteVolume dynamicMesh)
