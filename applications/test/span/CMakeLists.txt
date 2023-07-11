set(_FILES
  Test-stdFoam-span.C
)
add_executable(Test-stdFoam-span ${_FILES})
target_compile_features(Test-stdFoam-span PUBLIC cxx_std_11)
target_link_libraries(Test-stdFoam-span PUBLIC finiteVolume)
