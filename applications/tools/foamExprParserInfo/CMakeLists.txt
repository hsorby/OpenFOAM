set(_FILES
  foamExprParserInfo.C
)
add_executable(foamExprParserInfo ${_FILES})
target_compile_features(foamExprParserInfo PUBLIC cxx_std_11)
target_link_libraries(foamExprParserInfo PUBLIC finiteVolume)
