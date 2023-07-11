set(_FILES
  laminarFlameSpeed/laminarFlameSpeed.C
  laminarFlameSpeed/laminarFlameSpeedNew.C
  constant/constant.C
  Gulders/Gulders.C
  GuldersEGR/GuldersEGR.C
  RaviPetersen/RaviPetersen.C
)
add_library(laminarFlameSpeedModels ${_FILES})
target_compile_features(laminarFlameSpeedModels PUBLIC cxx_std_11)
target_include_directories(laminarFlameSpeedModels PUBLIC include PRIVATE includePrivate)
