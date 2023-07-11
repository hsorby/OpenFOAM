set(_FILES
  extrudeModel/extrudeModel.C
  extrudeModel/extrudeModelNew.C
  linearNormal/linearNormal.C
  planeExtrusion/planeExtrusion.C
  linearDirection/linearDirection.C
  linearRadial/linearRadial.C
  offsetSurface/offsetSurface.C
  radial/radial.C
  sigmaRadial/sigmaRadial.C
  sector/sector.C
  cyclicSector/cyclicSector.C
  wedge/wedge.C
  polyline/polyline.C
)
add_library(extrudeModel ${_FILES})
target_compile_features(extrudeModel PUBLIC cxx_std_11)
target_include_directories(extrudeModel PUBLIC include includePrivate)
target_link_libraries(extrudeModel PUBLIC OpenFOAM surfMesh meshTools blockMeshLib)
