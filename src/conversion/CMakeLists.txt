set(_FILES
  common/reader/meshReader.C
  common/reader/meshReaderAux.C
  common/reader/calcPointCells.C
  common/reader/createPolyCells.C
  common/reader/createPolyBoundary.C
  common/writer/meshWriter.C
  common/tables/boundaryRegion.C
  common/tables/cellTable.C
  fire/FIREMeshReader.C
  fire/FIREMeshWriter.C
  fire/checkFireEdges.C
  starcd/STARCDMeshReader.C
  starcd/STARCDMeshWriter.C
  polyDualMesh/polyDualMesh.C
  vtk/output/foamVtkSurfaceFieldWriter.C
)
add_library(conversion ${_FILES})
target_compile_features(conversion PUBLIC cxx_std_11)
target_include_directories(conversion PUBLIC include PRIVATE includePrivate)
