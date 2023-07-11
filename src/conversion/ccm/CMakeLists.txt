set(_FILES
  common/ccmBase.C
  common/ccmInternal.C
  reader/ccmReader.C
  reader/ccmReaderAux.C
  reader/ccmReaderMesh.C
  reader/ccmReaderSolution.C
  reader/ccmReaderOptions.C
  writer/ccmWriter.C
  writer/ccmWriterMesh.C
  writer/ccmWriterSolution.C
)
add_library(ccm ${_FILES})
target_compile_features(ccm PUBLIC cxx_std_11)
target_include_directories(ccm PUBLIC include PRIVATE includePrivate)
