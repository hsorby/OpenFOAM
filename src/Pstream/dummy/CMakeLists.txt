set(_FILES
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
add_library(Pstream ${_FILES})
target_compile_features(Pstream PUBLIC cxx_std_11)
target_include_directories(Pstream PUBLIC include PRIVATE includePrivate)
