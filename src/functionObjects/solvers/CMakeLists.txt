set(_FILES
  scalarTransport/scalarTransport.C
  energyTransport/energyTransport.C
  electricPotential/electricPotential.C
)
add_library(solverFunctionObjects ${_FILES})
target_compile_features(solverFunctionObjects PUBLIC cxx_std_11)
target_include_directories(solverFunctionObjects PUBLIC include PRIVATE includePrivate)
