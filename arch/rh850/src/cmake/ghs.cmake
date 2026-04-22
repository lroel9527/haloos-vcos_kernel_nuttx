# ##############################################################################
# arch/rh850/src/cmake/ghs.cmake
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

# Toolchain
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

# Cross compile: don't try to run executables during try-compile
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
# Disable Compiler tests
set(CMAKE_C_COMPILER_WORKS TRUE)                  # make CMake happy with GHS RH850
set(CMAKE_CXX_COMPILER_WORKS TRUE)                # make CMake happy with GHS RH850
set(CMAKE_C_ABI_COMPILED TRUE)                  # make CMake happy with GHS RH850
set(CMAKE_CXX_ABI_COMPILED TRUE)                # make CMake happy with GHS RH850
set(CMAKE_C_COMPILER_ID_RUN TRUE)
set(CMAKE_CXX_COMPILER_ID_RUN TRUE)
# ------------------------------------------------------------------------------
# Compilers 
# ------------------------------------------------------------------------------
set(CMAKE_ASM_COMPILER ccrh850)
set(CMAKE_C_COMPILER ccrh850)
set(CMAKE_CXX_COMPILER ccrh850)
set(CMAKE_STRIP gstrip)
set(CMAKE_OBJCOPY gmemfile)
set(CMAKE_OBJDUMP gdump)
set(CMAKE_LINKER ccrh850)
set(CMAKE_LD ccrh850)
set(CMAKE_AR ccrh850)
set(CMAKE_GMEMFILE gmemfile)
set(CMAKE_NM gnm)
set(CMAKE_RANLIB echo)
set(CMAKE_PREPROCESSOR ccrh850 -E -P)
set(CMAKE_ASM_SOURCE_FILE_EXTENSIONS 850;S;s)

# override the ARCHIVE command

set(CMAKE_ARCHIVE_COMMAND
    "<CMAKE_AR> <LINK_FLAGS> -archive <OBJECTS> -o <TARGET>")
set(CMAKE_C_ARCHIVE_CREATE ${CMAKE_ARCHIVE_COMMAND})
set(CMAKE_CXX_ARCHIVE_CREATE ${CMAKE_ARCHIVE_COMMAND})
set(CMAKE_ASM_ARCHIVE_CREATE ${CMAKE_ARCHIVE_COMMAND})

set(CMAKE_C_ARCHIVE_APPEND ${CMAKE_ARCHIVE_COMMAND})
set(CMAKE_CXX_ARCHIVE_APPEND ${CMAKE_ARCHIVE_COMMAND})
set(CMAKE_ASM_ARCHIVE_APPEND ${CMAKE_ARCHIVE_COMMAND})

# Architecture flags
# Ensure target CPU is applied to both compile and link.
set(GHS_COMMON_FLAGS
  -bsp=generic
  --preprocess_linker_directive
  -no_callt
  -sda=0
  -reserve_r2
  -large_sda
  --no_commons
  -shorten_loads
  -shorten_moves
  -ignore_callt_state_in_interrupts
  -additional_sda_reg=0
  -rh850_abi=ghs2014
  --prototype_errors
  --diag_suppress=826     # remove warning 826-D
  --diag_suppress=236     # remove warning 236-D
  --diag_suppress=68      # remove warning 68-D
  --diag_suppress=111     # remove warning 111-D
  --diag_suppress=174     # remove warning 174-D
  --diag_suppress=193     # remove warning 193-D
  --diag_suppress=1721    # remove warning 1721-D
  --diag_suppress=222     # remove warning 222-D
  --diag_suppress=257     # remove warning 257-D
  --diag_suppress=167     # remove warning 167-D
  --diag_suppress=1547    # remove warning 1547-D
  --diag_suppress=47      # remove warning 47-D
  --diag_suppress=1143    # remove warning 1143
  --diag_suppress=177     # remove warning 177
  --diag_suppress=170     # remove warning 170
  --diag_suppress=550      # remove warning 50
  --diag_suppress=59      # remove warning 59
  --diag_suppress=186     # remove warning 186
  --diag_suppress=301     # remove warning 301
)

set(GHS_COMPILE_FLAGS
  -Onone -w -g
  -prepare_dispose
  -inline_prologue
  -passsource
  --short_enum
  -dwarf2
  -Wshadow
  -delete
  -MMD
  -gnu99
  -nostdlib
)

# Keep link step clean: no -c / -MMD
set(GHS_LINK_FLAGS
  -map=nuttx.map
)

add_compile_options(${GHS_COMMON_FLAGS} ${GHS_COMPILE_FLAGS})
add_link_options(${GHS_COMMON_FLAGS} ${GHS_LINK_FLAGS})


# Endian
if(CONFIG_ENDIAN_BIG)
  add_compile_options(-mbig-endian)
  add_link_options(-mbig-endian)
endif()

# Entry symbol: must be passed as linker option "-e <symbol>"
# (like your command line: -e _Reset_Handler)
if(CONFIG_USE_START_SYMBOL)
  add_link_options(-e __start)
else()
  add_link_options(-entry=_Reset_Handler)
endif()

# Extra opts
if(CONFIG_DEBUG_CUSTOMOPT)
  add_compile_options(${CONFIG_DEBUG_OPTLEVEL})
endif()

if(CONFIG_DEBUG_SYMBOLS)
  add_compile_options(-dual_debug)
endif()


if(CONFIG_BSP_FSP_SUPPORT)
  add_compile_options(-DCONFIG_BSP_FSP_SUPPORT=1)
endif()

set(PREPROCESS ${CMAKE_C_COMPILER} ${CMAKE_C_FLAG_ARGS} -E -P)


# override nuttx_generate_preproces_target

set(NUTTX_TOOLCHAIN_PREPROCES_DEFINED true)

function(nuttx_generate_preproces_target)

  set(PREPROCESS_INCLUDE_FLAGS "-I${CMAKE_BINARY_DIR}/include"
                               "-I${NUTTX_CHIP_ABS_DIR}")

  if(CONFIG_RT_FRAMEWORK)
    LIST(APPEND PREPROCESS_INCLUDE_FLAGS "-I${GENDATA_DIR}/scripts")
  endif()

  # parse arguments into variables

  nuttx_parse_function_args(
    FUNC
    nuttx_generate_preproces_target
    ONE_VALUE
    SOURCE_FILE
    TARGET_FILE
    MULTI_VALUE
    DEPENDS
    REQUIRED
    SOURCE_FILE
    TARGET_FILE
    ARGN
    ${ARGN})

  add_custom_command(
    OUTPUT ${TARGET_FILE}
    COMMAND ${PREPROCESS} ${PREPROCESS_INCLUDE_FLAGS} -filetype.cpp
            ${SOURCE_FILE} -o ${TARGET_FILE}
    DEPENDS ${SOURCE_FILE} ${DEPENDS})

endfunction()

# override nuttx_find_toolchain_lib

set(NUTTX_FIND_TOOLCHAIN_LIB_DEFINED true)

function(nuttx_find_toolchain_lib)
  find_program(COMPILER_EXE "${CMAKE_C_COMPILER}")
  get_filename_component(GHS_ROOT_PATH "${COMPILER_EXE}" DIRECTORY)
  string(STRIP "${GHS_ROOT_PATH}" GHS_ROOT_PATH)
  if(NOT ARGN)
    nuttx_add_extra_library(${GHS_ROOT_PATH}/lib/rh850_compat/libarch.a)
    if(CONFIG_ARCH_FPU)
      if(CONFIG_ARM_FPU_ABI_SOFT)
        nuttx_add_extra_library(${GHS_ROOT_PATH}/lib/rh850_compat/libind_sf.a)
      elseif(CONFIG_ARCH_DPFPU)
        nuttx_add_extra_library(${GHS_ROOT_PATH}/lib/rh850_compat/libind_fp.a)
      else()
        nuttx_add_extra_library(${GHS_ROOT_PATH}/lib/rh850_compat/libind_sd.a)
      endif()
    else()
      nuttx_add_extra_library(${GHS_ROOT_PATH}/lib/rh850_compat/libind_sd.a)
    endif()
  endif()
endfunction()

# disable nuttx cmake link group otption
set(DISABLE_LINK_GROUP true)