set(_FILES
  foamCellZoneToVTK.C
)
add_executable(foamCellZoneToVTK ${_FILES})
target_compile_features(foamCellZoneToVTK PUBLIC cxx_std_11)
target_link_libraries(foamCellZoneToVTK PUBLIC finiteVolume)
