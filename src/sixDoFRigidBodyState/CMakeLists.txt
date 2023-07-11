set(_FILES
  sixDoFRigidBodyState.C
)
add_library(sixDoFRigidBodyState ${_FILES})
target_compile_features(sixDoFRigidBodyState PUBLIC cxx_std_11)
target_include_directories(sixDoFRigidBodyState PUBLIC include PRIVATE includePrivate)
