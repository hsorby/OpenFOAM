set(_FILES
  clouds/baseClasses/sprayCloud/sprayCloud.C
  parcels/derived/basicSprayParcel/defineBasicSprayParcel.C
  parcels/derived/basicSprayParcel/makeBasicSprayParcelSubmodels.C
)
add_library(lagrangianSpray ${_FILES})
target_compile_features(lagrangianSpray PUBLIC cxx_std_11)
target_include_directories(lagrangianSpray PUBLIC include PRIVATE includePrivate)
