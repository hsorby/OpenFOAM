set(_FILES
  scotchDecomp.C
)
add_library(scotchDecomp ${_FILES})
target_compile_features(scotchDecomp PUBLIC cxx_std_11)
target_include_directories(scotchDecomp PUBLIC include PRIVATE includePrivate)
target_link_libraries(scotchDecomp PUBLIC meshTools finiteVolume dynamicMesh decompositionMethods SCOTCH::scotch)
