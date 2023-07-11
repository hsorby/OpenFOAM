set(_FILES
  reaction/reactions/makeSolidReactions.C
)
add_library(solidSpecie ${_FILES})
target_compile_features(solidSpecie PUBLIC cxx_std_11)
target_include_directories(solidSpecie PUBLIC include PRIVATE includePrivate)
