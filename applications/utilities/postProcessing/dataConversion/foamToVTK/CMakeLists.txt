set(_FILES
  foamToVTK.C
)
add_executable(foamToVTK ${_FILES})
target_compile_features(foamToVTK PUBLIC cxx_std_11)
target_include_directories(foamToVTK PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(foamToVTK PUBLIC finiteVolume meshTools genericPatchFields lagrangianIntermediate conversion)
