set(_FILES
)
add_executable(Test-openmp ${_FILES})
target_compile_features(Test-openmp PUBLIC cxx_std_11)
target_link_libraries(Test-openmp PUBLIC finiteVolume)
