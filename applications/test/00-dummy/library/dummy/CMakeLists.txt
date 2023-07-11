set(_FILES
)
add_library(TestDummyMpi ${_FILES})
target_compile_features(TestDummyMpi PUBLIC cxx_std_11)
target_include_directories(TestDummyMpi PUBLIC include PRIVATE includePrivate)
