set(_FILES
)
add_executable(Test-dummyLib ${_FILES})
target_compile_features(Test-dummyLib PUBLIC cxx_std_11)
target_link_libraries(Test-dummyLib PUBLIC finiteVolume)
