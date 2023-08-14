set(_FILES
  setFields.C
)
add_executable(setFields ${_FILES})
target_compile_features(setFields PUBLIC cxx_std_11)
target_include_directories(setFields PRIVATE includePrivate)
target_link_libraries(setFields PUBLIC finiteArea finiteVolume meshTools)
