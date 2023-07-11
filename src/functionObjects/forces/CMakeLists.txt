set(_FILES
  forces/forces.C
  forceCoeffs/forceCoeffs.C
  propellerInfo/propellerInfo.C
)
add_library(forces ${_FILES})
target_compile_features(forces PUBLIC cxx_std_11)
target_include_directories(forces PUBLIC include PRIVATE includePrivate)
