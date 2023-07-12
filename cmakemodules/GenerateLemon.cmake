
find_program(M4_EXE NAMES m4 DOC "find the m4 application.")
mark_as_advanced(M4_EXE)

macro(LEMON_TARGET Name Input Output)

  set(LEMON_TARGET_usage
    "LEMON_TARGET(<Name> <Input> <Output> [COMPILE_FLAGS <string>] [TEMPLATE <string>]")

  set(LEMON_TARGET_PARAM_OPTIONS)
  set(LEMON_TARGET_PARAM_ONE_VALUE_KEYWORDS
    TEMPLATE
    )
  set(LEMON_TARGET_PARAM_MULTI_VALUE_KEYWORDS
    COMPILE_FLAGS
  )

  cmake_parse_arguments(
    LEMON_TARGET_ARG
    "${LEMON_TARGET_PARAM_OPTIONS}"
    "${LEMON_TARGET_PARAM_ONE_VALUE_KEYWORDS}"
    "${LEMON_TARGET_PARAM_MULTI_VALUE_KEYWORDS}"
    ${ARGN}
    )

  if(NOT "${LEMON_TARGET_ARG_UNPARSED_ARGUMENTS}" STREQUAL "")
    message(SEND_ERROR ${LEMON_TARGET_usage})
  else()

    set(_lemon_INPUT "${Input}")
    set(_lemon_OUTPUT "${Output}")
    set(_lemon_WORKING_DIR "${CMAKE_CURRENT_BINARY_DIR}")
    if(NOT IS_ABSOLUTE "${_lemon_INPUT}")
      set(_lemon_INPUT "${CMAKE_CURRENT_SOURCE_DIR}/${_lemon_INPUT}")
    endif()

    set(_lemon_OUTPUT "${Output}")
    if(NOT IS_ABSOLUTE ${_lemon_OUTPUT})
      set(_lemon_OUTPUT "${_lemon_WORKING_DIR}/${_lemon_OUTPUT}")
    endif()
    set(_lemon_TARGET_OUTPUTS "${_lemon_OUTPUT}")
    get_filename_component(_lemon_EXT ${_lemon_OUTPUT} LAST_EXT)
    set(_lemon_OUTPUT_EXT "-e${_lemon_EXT}")
    get_filename_component(_lemon_OUTPUT ${_lemon_OUTPUT} NAME_WE)

    set(_m4_EXE_OPTS "")
    if(NOT "${LEMON_TARGET_ARG_COMPILE_FLAGS}" STREQUAL "")
      set(_m4_EXE_OPTS "${LEMON_TARGET_ARG_COMPILE_FLAGS}")
      separate_arguments(_m4_EXE_OPTS)
    endif()

    set(_lemon_TEMPLATE_OPT "")
    if(NOT "${LEMON_TARGET_ARG_TEMPLATE}" STREQUAL "")
      set(_lemon_TEMPLATE_OPT "-T${LEMON_TARGET_ARG_TEMPLATE}")
    endif()

    add_custom_command(OUTPUT ${_lemon_TARGET_OUTPUTS}
      COMMAND ${M4_EXE} ${_m4_EXE_OPTS} ${_lemon_INPUT} > ${_lemon_OUTPUT}.lemon
      COMMAND $<TARGET_FILE:lemon> ${_lemon_TEMPLATE_OPT} ${_lemon_OUTPUT_EXT} ${_lemon_OUTPUT}.lemon
      VERBATIM
      COMMENT
            "[LEMON][${Name}] Generating state machine with Lemon ${LEMON_VERSION}"
      DEPENDS ${_lemon_INPUT}
      WORKING_DIRECTORY ${_lemon_WORKING_DIR}
    )

    set(LEMON_${Name}_DEFINED TRUE)
    set(LEMON_${Name}_OUTPUTS ${_lemon_TARGET_OUTPUTS})
    set(LEMON_${Name}_INPUT ${_lemon_INPUT})
    set(LEMON_${Name}_COMPILE_FLAGS ${_lemon_EXE_OPTS})

    unset(_lemon_EXE_OPTS)
    unset(_lemon_INPUT)
    unset(_lemon_OUTPUT)
    unset(_lemon_TARGET_OUTPUTS)
    unset(_lemon_WORKING_DIR)
    unset(_lemon_OUTPUT_EXT)
    unset(_lemon_EXT)
    unset(_lemon_TEMPLATE_OPT)
  endif()
endmacro()
