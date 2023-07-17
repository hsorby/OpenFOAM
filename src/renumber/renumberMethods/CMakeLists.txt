set(_FILES
  renumberMethod/renumberMethod.C
  manualRenumber/manualRenumber.C
  CuthillMcKeeRenumber/CuthillMcKeeRenumber.C
  randomRenumber/randomRenumber.C
  springRenumber/springRenumber.C
  structuredRenumber/structuredRenumber.C
  structuredRenumber/OppositeFaceCellWaveBase.C
)
add_library(renumberMethods ${_FILES})
target_compile_features(renumberMethods PUBLIC cxx_std_11)
target_link_libraries(renumberMethods PUBLIC OpenFOAM)
target_include_directories(renumberMethods PUBLIC include includePrivate structuredRenumber)
target_link_libraries(renumberMethods PUBLIC decompositionMethods)
