set(_FILES
  common/fileFormats.C
  common/manifoldCellsMeshObject.C
  colours/colourTable.C
  colours/colourTables.C
  colours/colourTools.C
  ensight/file/ensightCase.C
  ensight/file/ensightCaseOptions.C
  ensight/file/ensightFile.C
  ensight/file/ensightGeoFile.C
  ensight/file/ensightWriterCaching.C
  ensight/mesh/ensightMesh.C
  ensight/mesh/ensightMeshOptions.C
  ensight/output/ensightOutput.C
  ensight/part/cells/ensightCells.C
  ensight/part/cells/ensightCellsAddr.C
  ensight/part/cells/ensightCellsIO.C
  ensight/part/faces/ensightFaces.C
  ensight/part/faces/ensightFacesAddr.C
  ensight/part/faces/ensightFacesIO.C
  ensight/part/part/ensightPart.C
  ensight/part/surface/ensightOutputSurface.C
  ensight/read/ensightReadFile.C
  ensight/type/ensightPTraits.C
  abaqus/ABAQUSCore.C
  nastran/NASCore.C
  obj/OBJstream.C
  fire/FIRECore.C
  gltf/foamGltfAccessor.C
  gltf/foamGltfAnimation.C
  gltf/foamGltfBufferView.C
  gltf/foamGltfMesh.C
  gltf/foamGltfObject.C
  gltf/foamGltfScene.C
  gltf/foamGltfSceneWriter.C
  starcd/STARCDCore.C
  stl/STLCore.C
  stl/STLReader.C
  stl/STLAsciiParseManual.C
#  stl/STLAsciiParseRagel.cc
  vtk/base/foamVtkCore.C
  vtk/base/foamVtkPTraits.C
  vtk/file/foamVtkFileWriter.C
  vtk/file/foamVtkSeriesWriter.C
  vtk/file/foamVtmWriter.C
  vtk/format/foamVtkFormatter.C
  vtk/format/foamVtkAsciiFormatter.C
  vtk/format/foamVtkBase64Formatter.C
  vtk/format/foamVtkAppendBase64Formatter.C
  vtk/format/foamVtkAppendRawFormatter.C
  vtk/format/foamVtkBase64Layer.C
  vtk/format/foamVtkLegacyAsciiFormatter.C
  vtk/format/foamVtkLegacyRawFormatter.C
  vtk/output/foamVtkOutput.C
  vtk/output/foamVtkOutputOptions.C
  vtk/part/foamVtkMeshMaps.C
  vtk/part/foamVtuCells.C
  vtk/part/foamVtuSizing.C
  vtk/read/vtkUnstructuredReader.C
  vtk/write/foamVtkLineWriter.C
  vtk/write/foamVtkPolyWriter.C
  vtk/write/foamVtkSurfaceWriter.C
)
set(_INTERFACE_FILES ${CMAKE_CURRENT_BINARY_DIR}/STLAsciiParseFlex.C)
FLEX_TARGET(MyScanner stl/STLAsciiParseFlex.L "${_INTERFACE_FILES}" COMPILE_FLAGS --c++)

set(_RAGEL_FILE ${CMAKE_CURRENT_BINARY_DIR}/STLAsciiParseRagel.C)
RAGEL_TARGET(RagelScanner stl/STLAsciiParseRagel.rl "${_RAGEL_FILE}")

add_library(fileFormats ${_FILES} ${_INTERFACE_FILES} ${_RAGEL_FILE})
target_compile_features(fileFormats PUBLIC cxx_std_11)
target_include_directories(fileFormats PUBLIC
  include
  includePrivate
  ensight/file
  ensight/output
  ensight/part/surface
  gltf
  vtk/file
  vtk/format
  vtk/output
  vtk/read
  vtk/write
)
target_link_libraries(fileFormats PUBLIC OpenFOAM)
if (BUILD_SHARED_LIBS)
  target_link_options(OpenFOAM PUBLIC -undefined dynamic_lookup)
endif()
