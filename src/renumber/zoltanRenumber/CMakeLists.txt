set(_FILES
  zoltanRenumber.C
)
add_library(zoltanRenumber ${_FILES})
target_compile_features(zoltanRenumber PUBLIC cxx_std_11)
target_include_directories(zoltanRenumber PUBLIC include PRIVATE includePrivate)
