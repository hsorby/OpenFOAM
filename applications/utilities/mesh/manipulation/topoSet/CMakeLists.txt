set(_FILES
  topoSet.C
)
add_executable(topoSet ${_FILES})
target_compile_features(topoSet PUBLIC cxx_std_11)
target_link_libraries(topoSet PUBLIC meshTools)
