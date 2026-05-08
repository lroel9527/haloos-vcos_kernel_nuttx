# ##############################################################################
# arch/arm/src/cmake/armv8-r.cmake
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

set(PLATFORM_FLAGS)

if(CONFIG_ARCH_RH850G4MH)
  if(CONFIG_RH850_TOOLCHAIN_GHS)
    list(APPEND PLATFORM_FLAGS -cpu=rh850g4mh -D__RH850_G4MH__=1)
  endif()
endif()

add_compile_options(${PLATFORM_FLAGS})


