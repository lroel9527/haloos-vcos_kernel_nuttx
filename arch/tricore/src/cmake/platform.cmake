# ##############################################################################
# arch/tricore/src/cmake/platform.cmake
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

get_directory_property(TOOLCHAIN_DIR_FLAGS DIRECTORY ${CMAKE_SOURCE_DIR}
                                                     COMPILE_OPTIONS)

set(NUTTX_EXTRA_FLAGS "")
foreach(FLAG ${TOOLCHAIN_DIR_FLAGS})
  if(NOT FLAG MATCHES "^\\$<.*>$")
    if(NOT FLAG MATCHES "-nostdlib")
      list(APPEND NUTTX_EXTRA_FLAGS ${FLAG})
    endif()
  else()
    string(REGEX MATCH "\\$<\\$<COMPILE_LANGUAGE:C>:(.*)>" matched ${FLAG})
    if(matched)
      list(APPEND NUTTX_EXTRA_FLAGS ${CMAKE_MATCH_1})
    endif()
  endif()
endforeach()

separate_arguments(CMAKE_C_FLAG_ARGS NATIVE_COMMAND ${CMAKE_C_FLAGS})
if(CONFIG_TRICORE_TOOLCHAIN_HIGHTEC)

  execute_process(
    COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} ${NUTTX_EXTRA_FLAGS}
            --print-libgcc-file-name
    OUTPUT_STRIP_TRAILING_WHITESPACE
    OUTPUT_VARIABLE extra_library)
  list(APPEND EXTRA_LIB ${extra_library})
  if(CONFIG_LIBSUPCXX)
    execute_process(
      COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} ${NUTTX_EXTRA_FLAGS}
              --print-file-name=libsupc++.a
      OUTPUT_STRIP_TRAILING_WHITESPACE
      OUTPUT_VARIABLE extra_library)
    list(APPEND EXTRA_LIB ${extra_library})
  endif()
  if(CONFIG_ARCH_COVERAGE)
    execute_process(
      COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} ${NUTTX_EXTRA_FLAGS}
              --print-file-name=libgcov.a
      OUTPUT_STRIP_TRAILING_WHITESPACE
      OUTPUT_VARIABLE extra_library)
    list(APPEND EXTRA_LIB ${extra_library})
  endif()

  message(STATUS "EXTRA_LIB_CONFIG_TRICORE_TOOLCHAIN_HIGHTEC:  ${EXTRA_LIB}")
  nuttx_add_extra_library(${EXTRA_LIB})

  set(PREPROCESS ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} -E -P -x c)
elseif(CONFIG_TRICORE_TOOLCHAIN_GNU)
  execute_process(
    COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} ${NUTTX_EXTRA_FLAGS}
            --print-libgcc-file-name
    OUTPUT_STRIP_TRAILING_WHITESPACE
    OUTPUT_VARIABLE extra_library)
  list(APPEND EXTRA_LIB ${extra_library})
  if(NOT CONFIG_LIBM)
    execute_process(
      COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} ${NUTTX_EXTRA_FLAGS}
              --print-file-name=libm.a
      OUTPUT_STRIP_TRAILING_WHITESPACE
      OUTPUT_VARIABLE extra_library)
    list(APPEND EXTRA_LIB ${extra_library})
  endif()
  if(CONFIG_ARCH_TC4XX)
    # -nostdlib leaves startup under iLLD control. Keep the compiler's normal
    # constructor prologue/epilogue so Ifx_Ssw_doCppInit can call _init.
    foreach(crt_object crti.o crtbegin.o crtend.o crtn.o)
      execute_process(
        COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} ${NUTTX_EXTRA_FLAGS}
                --print-file-name=${crt_object}
        OUTPUT_STRIP_TRAILING_WHITESPACE
        OUTPUT_VARIABLE crt_path
        RESULT_VARIABLE crt_result)
      if(NOT crt_result EQUAL 0 OR NOT EXISTS "${crt_path}")
        message(FATAL_ERROR "TriCore GNU runtime object not found: ${crt_object}")
      endif()
      list(APPEND EXTRA_LIB "${crt_path}")
    endforeach()
  endif()
  if(CONFIG_ARCH_TC4XX AND CONFIG_RT_FRAMEWORK)
    # Extract only the CSA-aware jump implementation from libos. Linking
    # libos itself can pull semihosted POSIX stubs before the next group pass.
    execute_process(
      COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} ${NUTTX_EXTRA_FLAGS}
              --print-file-name=libos.a
      OUTPUT_STRIP_TRAILING_WHITESPACE
      OUTPUT_VARIABLE extra_library)
    if(NOT EXISTS "${extra_library}")
      message(FATAL_ERROR "TriCore GNU libos.a (setjmp/longjmp) not found")
    endif()
    set(TRICORE_SETJMP_DIR "${CMAKE_BINARY_DIR}/tricore_runtime")
    file(MAKE_DIRECTORY "${TRICORE_SETJMP_DIR}")
    set(TRICORE_SETJMP_OBJECT "${TRICORE_SETJMP_DIR}/setjmp.o")
    set(TRICORE_SETJMP_LIBRARY "${TRICORE_SETJMP_DIR}/libtricore_setjmp.a")
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${extra_library}")
    file(REMOVE "${TRICORE_SETJMP_OBJECT}")
    execute_process(
      COMMAND ${CMAKE_AR} x "${extra_library}" setjmp.o
      WORKING_DIRECTORY "${TRICORE_SETJMP_DIR}"
      RESULT_VARIABLE TRICORE_SETJMP_RESULT)
    if(NOT TRICORE_SETJMP_RESULT EQUAL 0 OR NOT EXISTS "${TRICORE_SETJMP_OBJECT}")
      message(FATAL_ERROR "Failed to extract GNU setjmp.o from libos.a")
    endif()
    execute_process(
      COMMAND ${CMAKE_AR} rcs "${TRICORE_SETJMP_LIBRARY}" "${TRICORE_SETJMP_OBJECT}"
      RESULT_VARIABLE TRICORE_SETJMP_RESULT)
    if(NOT TRICORE_SETJMP_RESULT EQUAL 0)
      message(FATAL_ERROR "Failed to create the GNU setjmp runtime archive")
    endif()
    list(APPEND EXTRA_LIB "${TRICORE_SETJMP_LIBRARY}")
  endif()
  if(CONFIG_LIBSUPCXX)
    execute_process(
      COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} ${NUTTX_EXTRA_FLAGS}
              --print-file-name=libsupc++.a
      OUTPUT_STRIP_TRAILING_WHITESPACE
      OUTPUT_VARIABLE extra_library)
    list(APPEND EXTRA_LIB ${extra_library})
  endif()
  if(CONFIG_ARCH_COVERAGE)
    execute_process(
      COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} ${NUTTX_EXTRA_FLAGS}
              --print-file-name=libgcov.a
      OUTPUT_STRIP_TRAILING_WHITESPACE
      OUTPUT_VARIABLE extra_library)
    list(APPEND EXTRA_LIB ${extra_library})
  endif()

  nuttx_add_extra_library(${EXTRA_LIB})
endif()
