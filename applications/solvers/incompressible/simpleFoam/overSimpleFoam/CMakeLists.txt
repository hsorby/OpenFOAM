set(_FILES
  overSimpleFoam.C
)
add_executable(overSimpleFoam ${_FILES})
target_include_directories(overSimpleFoam PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(overSimpleFoam PUBLIC cxx_std_11)
target_link_libraries(overSimpleFoam PUBLIC
  finiteVolume
  meshTools
  incompressibleTurbulenceModels
  compressibleTurbulenceModels
  fvOptions
  atmosphericModels
  topoChangerFvMesh
  overset
) # fvOptions sampling
