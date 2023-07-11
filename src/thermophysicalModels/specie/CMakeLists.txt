set(_FILES
  atomicWeights/atomicWeights.C
  specie/specie.C
  reaction/reactions/makeReactions.C
  reaction/reactions/makeLangmuirHinshelwoodReactions.C
)
add_library(specie ${_FILES})
target_compile_features(specie PUBLIC cxx_std_11)
target_include_directories(specie PUBLIC include PRIVATE includePrivate)
