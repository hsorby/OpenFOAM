set(_FILES
  SloanRenumber.C
)
add_library(SloanRenumber ${_FILES})
target_compile_features(SloanRenumber PUBLIC cxx_std_11)
target_include_directories(SloanRenumber PUBLIC include PRIVATE includePrivate)
