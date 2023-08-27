
add_subdirectory(extractionMethod)

set(_FILES
  surfaceFeatureExtract.C
)
add_executable(surfaceFeatureExtract ${_FILES})
target_include_directories(surfaceFeatureExtract PRIVATE includePrivate)
target_compile_features(surfaceFeatureExtract PUBLIC cxx_std_11)
target_link_libraries(surfaceFeatureExtract PUBLIC finiteVolume dynamicMesh extractionMethod)
