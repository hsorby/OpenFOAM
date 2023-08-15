set(_FILES
  decomposePar.C

  domainDecomposition.C
  domainDecompositionMesh.C
  domainDecompositionDistribute.C
  domainDecompositionWrite.C

  domainDecompositionDryRun.C
  domainDecompositionDryRunWrite.C
)
add_executable(decomposePar ${_FILES})
target_include_directories(decomposePar PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(decomposePar PUBLIC cxx_std_11)
target_link_libraries(decomposePar PUBLIC finiteArea finiteVolume dynamicMesh decompose faDecompose)
#    -lfiniteArea \
#    -lfiniteVolume \
#    -lfileFormats \
#    -lmeshTools \
#    -llagrangian \
#    -ldynamicMesh \
#    -lgenericPatchFields \
#    -ldecompositionMethods \
#    -ldecompose \
#    -lfaDecompose \
#    -L$(FOAM_LIBBIN)/dummy \
#    -lkahipDecomp -lmetisDecomp -lscotchDecomp
