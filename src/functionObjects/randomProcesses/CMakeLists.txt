set(_FILES
  energySpectrum/energySpectrum.C
)
add_library(randomProcessesFunctionObjects ${_FILES})
target_compile_features(randomProcessesFunctionObjects PUBLIC cxx_std_11)
target_include_directories(randomProcessesFunctionObjects PUBLIC include PRIVATE includePrivate)
