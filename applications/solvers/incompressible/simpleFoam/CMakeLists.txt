set(_FILES
  simpleFoam.C
)
add_executable(simpleFoam ${_FILES})
target_include_directories(simpleFoam PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(simpleFoam PUBLIC cxx_std_11)
target_link_libraries(simpleFoam PUBLIC
  finiteVolume
  meshTools
  incompressibleTurbulenceModels
  compressibleTurbulenceModels
  fvOptions
  atmosphericModels
  SLGThermo
) # fvOptions sampling
