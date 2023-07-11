set(_FILES
  Test-GAMGAgglomeration.C
)
add_executable(Test-GAMGAgglomeration ${_FILES})
target_compile_features(Test-GAMGAgglomeration PUBLIC cxx_std_11)
target_link_libraries(Test-GAMGAgglomeration PUBLIC finiteVolume)
