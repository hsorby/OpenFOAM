set(_FILES
  ptscotchDecomp.C
)
add_library($(FOAM_MPI_LIBBIN)/libptscotchDecomp ${_FILES})
target_compile_features($(FOAM_MPI_LIBBIN)/libptscotchDecomp PUBLIC cxx_std_11)
target_include_directories($(FOAM_MPI_LIBBIN)/libptscotchDecomp PUBLIC include PRIVATE includePrivate)
