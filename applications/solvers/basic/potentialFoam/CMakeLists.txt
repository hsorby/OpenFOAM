set(_FILES
  potentialFoam.C
)
add_executable(potentialFoam ${_FILES})
target_include_directories(potentialFoam PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(potentialFoam PUBLIC cxx_std_11)
target_link_libraries(potentialFoam PUBLIC finiteVolume meshTools)
