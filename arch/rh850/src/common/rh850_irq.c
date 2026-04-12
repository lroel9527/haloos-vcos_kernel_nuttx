/****************************************************************************
 * arch/arm/src/samd5e5/sam_irq.c
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

#include <stdint.h>
#include <assert.h>
#include <debug.h>

#include <nuttx/arch.h>
#include <arch/irq.h>
#include <sched/sched.h>

#if (CONFIG_BSP_FSP_SUPPORT)
#include "bsp_api.h"
#else
#include "Device_common.h"
#endif


/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/


/****************************************************************************
 * Private Functions
 ****************************************************************************/


/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_irqinitialize
 ****************************************************************************/
#define INTOSTM0TINT            360

#define IRQ_UNMAPPED            0xff

static void *archctxhandle[1];


void up_set_contexthdl(void *const ctxhdl)
{
	irqstate_t irq_state = up_irq_save();

	archctxhandle[0] = ctxhdl;
	up_irq_restore(irq_state);
	return;
}

void *up_get_contexthdl()
{
	return archctxhandle[0];
}


void up_irqinitialize(void)
{
  #if (CONFIG_BSP_FSP_SUPPORT)
  /* Initialize interrupt */
  bsp_irq_cfg();
 #endif 
}

/****************************************************************************
 * Name: up_disable_irq
 *
 * Description:
 *   Disable the IRQ specified by 'irq'
 *
 ****************************************************************************/

void up_disable_irq(int irq)
{
    RH850_IRQ_DisableIRQ( irq);
}

/****************************************************************************
 * Name: up_enable_irq
 *
 * Description:
 *   Enable the IRQ specified by 'irq'
 *
 ****************************************************************************/

void up_enable_irq(int irq)
{
  RH850_IRQ_EnableIRQ(irq);
}
/****************************************************************************
 * Name: up_prioritize_irq
 *
 * Description:
 *   Set the priority of an IRQ.
 *
 *   Since this API is not supported on all architectures, it should be
 *   avoided in common implementations where possible.
 *
 ****************************************************************************/

#ifdef CONFIG_ARCH_IRQPRIO
int up_prioritize_irq(int irq, int priority)
{
  
  RH850_IRQ_SetPriority((uint32_t) irq, (uint32_t) priority);
  return OK;
}
#endif



void up_trigger_irq(int irq, cpu_set_t cpuset)
{

}