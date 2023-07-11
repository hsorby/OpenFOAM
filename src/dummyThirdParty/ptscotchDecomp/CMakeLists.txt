set(_FILES
  dummyPtscotchDecomp.C
)
add_library(ptscotchDecomp ${_FILES})
target_compile_features(ptscotchDecomp PUBLIC cxx_std_11)
target_include_directories(ptscotchDecomp PUBLIC include PRIVATE includePrivate)
