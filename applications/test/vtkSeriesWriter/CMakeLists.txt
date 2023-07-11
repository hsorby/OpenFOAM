set(_FILES
  Test-vtkSeriesWriter.C
)
add_executable(Test-vtkSeriesWriter ${_FILES})
target_compile_features(Test-vtkSeriesWriter PUBLIC cxx_std_11)
target_link_libraries(Test-vtkSeriesWriter PUBLIC finiteVolume)
