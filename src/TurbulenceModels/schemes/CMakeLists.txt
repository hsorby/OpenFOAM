set(_FILES
  DEShybrid/DEShybrid.C
)
add_library(turbulenceModelSchemes ${_FILES})
target_compile_features(turbulenceModelSchemes PUBLIC cxx_std_11)
target_include_directories(turbulenceModelSchemes PUBLIC include includePrivate)
target_link_libraries(turbulenceModelSchemes PUBLIC turbulenceModels)
