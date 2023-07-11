set(_FILES
  Test-CompactListList.C
)
add_executable(Test-CompactListList ${_FILES})
target_compile_features(Test-CompactListList PUBLIC cxx_std_11)
target_link_libraries(Test-CompactListList PUBLIC finiteVolume)
