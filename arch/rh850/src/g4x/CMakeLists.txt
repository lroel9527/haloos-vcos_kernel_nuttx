# ##############################################################################
# arch/arm/src/armv8-m/CMakeLists.txt
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

set(SRCS)

if(CONFIG_ARCH_TOOLCHAIN_GHS)
    list(
        APPEND SRCS 
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Template/RH850/Source/ghs/system.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Template/RH850/Source/Interrupt_VectorTable_PE0.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Template/RH850/Source/Interrupt_VectorTable_PE1.c
    )
endif()

FILE(GLOB_RECURSE ASRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Template/RH850/Source/ghs/*.850
)

enable_language(ASM)
foreach(X IN ITEMS ${ASRCS})
  set_source_files_properties(${X} PROPERTIES LANGUAGE ASM)
endforeach()


target_sources(arch PRIVATE ${SRCS})
target_sources(arch PUBLIC ${ASRCS})

