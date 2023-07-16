set(_FILES
  atomicWeights/atomicWeights.C
  specie/specie.C
  reaction/reactions/makeReactions.C
  reaction/reactions/makeLangmuirHinshelwoodReactions.C
)
add_library(specie ${_FILES})
target_compile_features(specie PUBLIC cxx_std_11)
target_include_directories(specie
  PUBLIC
    include
    includePrivate
    equationOfState/Boussinesq
    equationOfState/PengRobinsonGas
    equationOfState/adiabaticPerfectFluid
    equationOfState/icoPolynomial
    equationOfState/icoTabulated
    equationOfState/incompressiblePerfectGas
    equationOfState/linear
    equationOfState/perfectFluid
    equationOfState/perfectGas
    equationOfState/rPolynomial
    equationOfState/rhoConst
    reaction/Reactions/IrreversibleReaction
    reaction/Reactions/NonEquilibriumReversibleReaction
    reaction/Reactions/Reaction
    reaction/Reactions/ReactionList
    reaction/Reactions/ReversibleReaction
    thermo/eConst
    thermo/hConst
    thermo/hPolynomial
    thermo/hPower
    thermo/hTabulated
    thermo/janaf
    thermo/thermo
    transport/WLF
    transport/const
    transport/logPolynomial
    transport/polynomial
    transport/sutherland
    transport/tabulated
)
target_link_libraries(specie PUBLIC finiteVolume thermophysicalProperties)
if (BUILD_SHARED_LIBS)
  target_link_options(specie PUBLIC -undefined dynamic_lookup)
endif()
