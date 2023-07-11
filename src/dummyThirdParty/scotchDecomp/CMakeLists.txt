set(_FILES
  dummyScotchDecomp.C
)
add_library(scotchDecomp ${_FILES})
target_compile_features(scotchDecomp PUBLIC cxx_std_11)
target_include_directories(scotchDecomp PUBLIC include PRIVATE includePrivate)
