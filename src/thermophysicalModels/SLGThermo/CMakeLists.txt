set(_FILES
  SLGThermo/SLGThermo.C
)
add_library(SLGThermo ${_FILES})
target_compile_features(SLGThermo PUBLIC cxx_std_11)
target_include_directories(SLGThermo PUBLIC include PRIVATE includePrivate)
