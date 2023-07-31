set(_FILES
  faOption/faOption.C
  faOption/faOptionIO.C
  faOption/faOptionList.C
  faOption/faOptions.C
  faceSetOption/faceSetOption.C
  sources/derived/externalHeatFluxSource/externalHeatFluxSource.C
  sources/derived/jouleHeatingSource/jouleHeatingSource.C
  sources/derived/contactHeatFluxSource/contactHeatFluxSource.C
  sources/derived/externalFileSource/externalFileSource.C
  corrections/limitVelocity/limitVelocity.C
  corrections/limitHeight/limitHeight.C
)
add_library(faOptions ${_FILES})
target_compile_features(faOptions PUBLIC cxx_std_11)
target_include_directories(faOptions PUBLIC include includePrivate faOption sources/derived/jouleHeatingSource)
target_link_libraries(faOptions PUBLIC finiteVolume finiteArea sampling incompressibleTurbulenceModels compressibleTurbulenceModels thermoTools)
