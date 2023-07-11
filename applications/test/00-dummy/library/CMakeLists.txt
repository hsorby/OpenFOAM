set(_FILES
)
add_library(TestDummy-OpenFOAM ${_FILES})
target_compile_features(TestDummy-OpenFOAM PUBLIC cxx_std_11)
target_include_directories(TestDummy-OpenFOAM PUBLIC include PRIVATE includePrivate)
