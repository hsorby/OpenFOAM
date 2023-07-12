find_program(RAGEL_EXECUTABLE NAMES ragel DOC "path to the ragel executable")
mark_as_advanced(RAGEL_EXECUTABLE)

if(RAGEL_EXECUTABLE)

  execute_process(COMMAND ${RAGEL_EXECUTABLE} --version
    OUTPUT_VARIABLE RAGEL_version_output
    ERROR_VARIABLE  RAGEL_version_error
    RESULT_VARIABLE RAGEL_version_result
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  if(${RAGEL_version_result} EQUAL 0)
    string(REGEX REPLACE "^Ragel State Machine Compiler version ([^ ]+) .*$"
                         "\\1"
                         RAGEL_VERSION "${RAGEL_version_output}")
  else()
    message(SEND_ERROR
            "Command \"${RAGEL_EXECUTABLE} --version\" failed with output:
${RAGEL_version_error}")
  endif()

  #============================================================
  # RAGEL_TARGET (public macro)
  #============================================================
  #
  macro(RAGEL_TARGET Name Input Output)
    set(RAGEL_TARGET_usage
              "RAGEL_TARGET(<Name> <Input> <Output> [COMPILE_FLAGS <string>]")
    set(RAGEL_TARGET_PARAM_OPTIONS)
    set(RAGEL_TARGET_PARAM_ONE_VALUE_KEYWORDS
      COMPILE_FLAGS
      )
    set(RAGEL_TARGET_PARAM_MULTI_VALUE_KEYWORDS)

    cmake_parse_arguments(
      RAGEL_TARGET_ARG
      "${RAGEL_TARGET_PARAM_OPTIONS}"
      "${RAGEL_TARGET_PARAM_ONE_VALUE_KEYWORDS}"
      "${RAGEL_TARGET_PARAM_MULTI_VALUE_KEYWORDS}"
      ${ARGN}
      )

    if(NOT "${RAGEL_TARGET_ARG_UNPARSED_ARGUMENTS}" STREQUAL "")
      message(SEND_ERROR ${RAGEL_TARGET_usage})
    else()

      set(_ragel_INPUT "${Input}")
      set(_ragel_WORKING_DIR "${CMAKE_CURRENT_BINARY_DIR}")
      if(NOT IS_ABSOLUTE "${_ragel_INPUT}")
        set(_ragel_INPUT "${CMAKE_CURRENT_SOURCE_DIR}/${_ragel_INPUT}")
      endif()

      set(_ragel_OUTPUT "${Output}")
      if(NOT IS_ABSOLUTE ${_ragel_OUTPUT})
        set(_ragel_OUTPUT "${_ragel_WORKING_DIR}/${_ragel_OUTPUT}")
      endif()
      set(_ragel_TARGET_OUTPUTS "${_ragel_OUTPUT}")

      set(_ragel_EXE_OPTS "")
      if(NOT "${RAGEL_TARGET_ARG_COMPILE_FLAGS}" STREQUAL "")
        set(_ragel_EXE_OPTS "${RAGEL_TARGET_ARG_COMPILE_FLAGS}")
        separate_arguments(_ragel_EXE_OPTS)
      endif()

      add_custom_command(OUTPUT ${_ragel_TARGET_OUTPUTS}
        COMMAND ${RAGEL_EXECUTABLE}
        ARGS    ${_ragel_EXE_OPTS} -o${_ragel_OUTPUT} ${_ragel_INPUT}
        VERBATIM
        DEPENDS ${_ragel_INPUT}
        COMMENT
            "[RAGEL][${Name}] Compiling state machine with Ragel ${RAGEL_VERSION}"
        WORKING_DIRECTORY ${_ragel_WORKING_DIR})

      set(RAGEL_${Name}_DEFINED TRUE)
      set(RAGEL_${Name}_OUTPUTS ${_ragel_TARGET_OUTPUTS})
      set(RAGEL_${Name}_INPUT ${_ragel_INPUT})
      set(RAGEL_${Name}_COMPILE_FLAGS ${_ragel_EXE_OPTS})
      set(RAGEL_${Name}_OUTPUT_HEADER ${_ragel_OUTPUT_HEADER})

      unset(_ragel_EXE_OPTS)
      unset(_ragel_INPUT)
      unset(_ragel_OUTPUT)
      unset(_ragel_OUTPUT_HEADER)
      unset(_ragel_OUTPUT_HEADER_ABS)
      unset(_ragel_TARGET_OUTPUTS)
      unset(_ragel_WORKING_DIR)
    endif()
  endmacro()

endif()

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(RAGEL REQUIRED_VARS  RAGEL_EXECUTABLE
                                        VERSION_VAR    RAGEL_VERSION)
