/****************************************************************************
 * arch/rh850/src/common/rh850_udelay.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <sys/types.h>
#include <nuttx/arch.h>

#include "bsp_api.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_udelay
 *
 * Description:
 *   Delay inline for the requested number of microseconds.  NOTE:  Because
 *   of all of the setup, several microseconds will be lost before the actual
 *   timing loop begins.  Thus, the delay will always be a few microseconds
 *   longer than requested.
 *
 *   *** NOT multi-tasking friendly ***
 *
 ****************************************************************************/
#include <stdint.h>
#define CPU_CLOCK_HZ   800000000UL

static inline void sw_delay_loop(uint32_t loop)
{
    while (loop--)
    {
        __asm__ volatile ("nop");
    }
}

void sw_delay_us(uint32_t us)
{
    /* Calibrate this value on real hardware */
    const uint32_t cycles_per_loop = 4U;
    const uint32_t loops_per_us =
        (CPU_CLOCK_HZ / 1000000UL) / cycles_per_loop;

    while (us--)
    {
        sw_delay_loop(loops_per_us);
    }
}

void up_udelay(useconds_t microseconds)
{
  #ifdef CONFIG_BSP_FSP_SUPPORT
    R_BSP_SoftwareDelay((uint32_t)microseconds, BSP_DELAY_UNITS_MICROSECONDS);
  #else
  #define RH850_CPU_CYCLE_HZ    800000000
    sw_delay_us((uint32_t)microseconds)
  #endif
}






