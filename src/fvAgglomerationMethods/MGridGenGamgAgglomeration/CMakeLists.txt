set(_FILES
  MGridGenGAMGAgglomeration.C
  MGridGenGAMGAgglomerate.C
)
add_library(MGridGenGAMGAgglomeration ${_FILES})
target_compile_features(MGridGenGAMGAgglomeration PUBLIC cxx_std_11)
target_include_directories(MGridGenGAMGAgglomeration PUBLIC include PRIVATE includePrivate)
