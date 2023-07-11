set(_FILES
  kahipDecomp.C
)
add_library(kahipDecomp ${_FILES})
target_compile_features(kahipDecomp PUBLIC cxx_std_11)
target_include_directories(kahipDecomp PUBLIC include PRIVATE includePrivate)
