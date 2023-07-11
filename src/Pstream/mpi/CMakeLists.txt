set(_FILES
  PstreamGlobals.C
  UPstream.C
  UPstreamAllToAll.C
  UPstreamBroadcast.C
  UPstreamGatherScatter.C
  UPstreamReduce.C
  UPstreamRequest.C
  UIPstreamRead.C
  UOPstreamWrite.C
  UIPBstreamRead.C
  UOPBstreamWrite.C
)
add_library($(FOAM_MPI_LIBBIN)/libPstream ${_FILES})
target_compile_features($(FOAM_MPI_LIBBIN)/libPstream PUBLIC cxx_std_11)
target_include_directories($(FOAM_MPI_LIBBIN)/libPstream PUBLIC include PRIVATE includePrivate)
