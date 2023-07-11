set(_FILES
)
add_library($(FOAM_MPI_LIBBIN)/libTestDummyMpi ${_FILES})
target_compile_features($(FOAM_MPI_LIBBIN)/libTestDummyMpi PUBLIC cxx_std_11)
target_include_directories($(FOAM_MPI_LIBBIN)/libTestDummyMpi PUBLIC include PRIVATE includePrivate)
