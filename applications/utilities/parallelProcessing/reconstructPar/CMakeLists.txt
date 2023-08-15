set(_FILES
  reconstructPar.C
)
add_executable(reconstructPar ${_FILES})
target_include_directories(reconstructPar PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(reconstructPar PUBLIC cxx_std_11)
target_link_libraries(reconstructPar PUBLIC finiteArea finiteVolume dynamicMesh reconstruct faReconstruct)
