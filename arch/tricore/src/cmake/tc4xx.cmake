# ##############################################################################
# arch/tricore/src/cmake/tc4xx.cmake
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

if(NOT CONFIG_ARCH_CHIP_CUSTOM_TC499N)
  message(FATAL_ERROR "No TC4xx platform profile for the selected chip")
endif()

if(CONFIG_TRICORE_TOOLCHAIN_GNU)
  set(PLATFORM_FLAGS -mcpu=tc49Ax)
elseif(CONFIG_TRICORE_TOOLCHAIN_TASKING)
  set(PLATFORM_FLAGS --cpu=tc49xn)
endif()

set(TC499_ILLD_DIR ${NUTTX_CHIP_ABS_DIR}/../../drivers/TC49xN)
list(APPEND PLATFORM_FLAGS
     -I${TC499_ILLD_DIR}/Libraries/iLLD/TC49xN/Tricore/Cpu/Std
     -I${TC499_ILLD_DIR}/Libraries/Infra/Platform
     -I${TC499_ILLD_DIR}/Libraries/Infra/Platform/Tricore/Compilers
     -I${TC499_ILLD_DIR}/Configurations)
add_compile_options(${PLATFORM_FLAGS})
if(CONFIG_TRICORE_TOOLCHAIN_GNU)
  add_link_options(-mcpu=tc49Ax)
else()
  add_link_options(-Ctc49xn)
endif()
