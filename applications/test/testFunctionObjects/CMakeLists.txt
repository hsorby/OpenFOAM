set(_FILES
  fakeError/fakeErrorFunctionObject.C
)
add_library($(FOAM_USER_LIBBIN)/libtestFunctionObjects ${_FILES})
target_compile_features($(FOAM_USER_LIBBIN)/libtestFunctionObjects PUBLIC cxx_std_11)
target_include_directories($(FOAM_USER_LIBBIN)/libtestFunctionObjects PUBLIC include PRIVATE includePrivate)
