set(_FILES
  router.C
  Test-processorRouter.C
)
add_executable(Test-processorRouter ${_FILES})
target_compile_features(Test-processorRouter PUBLIC cxx_std_11)
target_link_libraries(Test-processorRouter PUBLIC finiteVolume)
