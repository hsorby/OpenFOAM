set(_FILES
  surfaceFeaturesExtraction.C
  extractFromFile.C
  extractFromNone.C
  extractFromSurface.C
)
add_library(extractionMethod ${_FILES})
target_include_directories(extractionMethod PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(extractionMethod PUBLIC cxx_std_11)
target_link_libraries(extractionMethod PUBLIC finiteVolume dynamicMesh)
