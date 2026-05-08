# ##############################################################################
# arch/rh850/src/cmake/Toolchain.cmake
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

set(ARCH_SUBDIR)
set(COREPROFILE)

if(CONFIG_ARCH_RH850G4MH)     # RH850G4MH
  set(COREPROFILE rh850g4mh)
  set(ARCH_SUBDIR g4x)
elseif(CONFIG_ARCH_RH850G4KH) # RH850G4KH
  set(COREPROFILE rh850g4kh)
  set(ARCH_SUBDIR g4x)
endif()

include(${COREPROFILE})

set(TOOLCHAIN_FILE)

if(CONFIG_ARCH_TOOLCHAIN_CLANG)         # clang
  set(TOOLCHAIN_FILE clang)
elseif(CONFIG_ARCH_TOOLCHAIN_GHS)       # greenhills
  set(TOOLCHAIN_FILE ghs)
elseif(CONFIG_ARCH_TOOLCHAIN_HIGHTEC)   # HighTec
  set(TOOLCHAIN_FILE HighTec)
else()                                  # gcc
  set(TOOLCHAIN_FILE gcc)
endif()

include(${TOOLCHAIN_FILE})

