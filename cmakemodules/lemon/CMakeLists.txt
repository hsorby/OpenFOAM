

add_executable(lemon lemon.c)
set_target_properties(lemon
  PROPERTIES LEMON_TEMPLATE "${CMAKE_CURRENT_SOURCE_DIR}/lempar.c"
)
