# ##############################################################################
# arch/arm/src/cmake/platform.cmake
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

# configure target processor

if(CONFIG_ARCH_RH850G4MH)
  set(CMAKE_SYSTEM_PROCESSOR rh850g4mh)
elseif(CONFIG_ARCH_RH850G4KH)
  set(CMAKE_SYSTEM_PROCESSOR rh850g4kh)
else()
  message(FATAL_ERROR "CMAKE_SYSTEM_PROCESSOR not set")
endif()

get_directory_property(TOOLCHAIN_DIR_FLAGS DIRECTORY ${CMAKE_SOURCE_DIR}
                                                     COMPILE_OPTIONS)

set(NUTTX_EXTRA_FLAGS "")
foreach(FLAG ${TOOLCHAIN_DIR_FLAGS})
  if(NOT FLAG MATCHES "^\\$<.*>$")
    list(APPEND NUTTX_EXTRA_FLAGS ${FLAG})
  else()
    string(REGEX MATCH "\\$<\\$<COMPILE_LANGUAGE:C>:(.*)>" matched ${FLAG})
    if(matched)
      list(APPEND NUTTX_EXTRA_FLAGS ${CMAKE_MATCH_1})
    endif()
  endif()
endforeach()

separate_arguments(CMAKE_C_FLAG_ARGS NATIVE_COMMAND ${CMAKE_C_FLAGS})

if(NOT CONFIG_ARCH_TOOLCHAIN_HIGHTEC)
  nuttx_find_toolchain_lib()

  if(NOT CONFIG_LIBM)
    nuttx_find_toolchain_lib(libm.a)
  endif()

  if(CONFIG_LIBSUPCXX_TOOLCHAIN)
    nuttx_find_toolchain_lib(libsupc++.a)
  endif()

  if(CONFIG_SCHED_GCOV)
    nuttx_find_toolchain_lib(libgcov.a)
  endif()
else()
  if(NOT CONFIG_LIBM)
    nuttx_find_toolchain_lib(libm.a)
  endif()

  if(NOT CONFIG_LIBC)
    nuttx_find_toolchain_lib(libc.a)
  endif()

  if(NOT CONFIG_LIBG)
    nuttx_find_toolchain_lib(libg.a)
  endif()
endif()