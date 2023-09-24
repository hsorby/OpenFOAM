set(_FILES
  mapFields.C
  mapLagrangian.C
)
add_executable(mapFields ${_FILES})
target_compile_features(mapFields PUBLIC cxx_std_11)
target_include_directories(mapFields PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mapFields PUBLIC finiteVolume meshTools sampling lagrangian decompose decompositionMethods genericPatchFields)

