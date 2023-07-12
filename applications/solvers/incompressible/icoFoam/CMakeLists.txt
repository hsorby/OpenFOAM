set(_FILES
  icoFoam.C
)
add_executable(icoFoam ${_FILES})
target_include_directories(icoFoam PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(icoFoam PUBLIC cxx_std_11)
target_link_libraries(icoFoam PUBLIC finiteVolume meshTools)
