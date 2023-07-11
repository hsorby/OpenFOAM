set(_FILES
  dummyMGridGen.C
)
add_library(MGridGen ${_FILES})
target_compile_features(MGridGen PUBLIC cxx_std_11)
target_include_directories(MGridGen PUBLIC include PRIVATE includePrivate)
