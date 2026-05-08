/****************************************************************************
 * arch/renesas/include/irq.h
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

/* This file should never be included directly but, rather,
 * only indirectly through nuttx/irq.h
 */

#ifndef __ARCH_RH850_INCLUDE_IRQ_H
#define __ARCH_RH850_INCLUDE_IRQ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <sys/types.h>
#ifndef __ASSEMBLY__
#  include <stdbool.h>
#endif

#ifndef __ASSEMBLY__
#if defined(CONFIG_RT_FRAMEWORK) && (CONFIG_RT_FRAMEWORK == 1)
#include <arch/u2bx/atomic.h>
#endif /* CONFIG_RT_FRAMEWORK */
#endif

#include <nuttx/irq.h>
#include <arch/u2bx/irq.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__
#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* This holds a references to the current interrupt level
 * register storage structure.  It is non-NULL only during
 * interrupt processing.
 */

EXTERN volatile uint32_t *g_current_regs;

EXTERN const uintptr_t g_idle_topstack;

extern void up_set_contexthdl(void *const ctxhdl);

extern void *up_get_contexthdl();

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#if defined(CONFIG_RT_FRAMEWORK) && (CONFIG_RT_FRAMEWORK == 1)
void up_init_irq(int irq, int irq_prio);
int  up_trigger_ipicall(unsigned int cpu);
void up_trigger_ipicalls(unsigned int cpu_mask);
void up_ipicall_attach(void *handler);
bool up_irq_is_enabled(int irq);
void up_clear_irq(int irq);
int up_timer_value(FAR clock_t *ticks);
uint32_t up_timer_freq(void);
#endif

/****************************************************************************
 * Inline functions
 ****************************************************************************/

static inline_function uint32_t *up_current_regs(void)
{
  return (uint32_t *)g_current_regs;
}


static inline_function void up_set_current_regs(uint32_t *regs)
{
  g_current_regs = regs;
}


static inline_function void up_irq_level_restore(irqlevel_t level)
{
//   up_set_irq_mask_level(level);
}

static inline_function void up_kernel_int_restore(irqlevel_t level)
{
#if defined(CONFIG_RT_FRAMEWORK_INT_LEVEL) && (CONFIG_RT_FRAMEWORK_INT_LEVEL == 1)
  return up_irq_level_restore(level);
#else
  return up_irq_restore(level);
#endif
}


static inline_function irqlevel_t up_irq_level_save(irqlevel_t level)
{
//   irqlevel_t pre_level = up_get_irq_mask_level();

//   if (level < pre_level) {
//     up_set_irq_mask_level(level);
//   }
//   return pre_level;
	return 0;
}

static inline_function irqlevel_t up_kernel_int_save(void)
{
#if defined(CONFIG_RT_FRAMEWORK_INT_LEVEL) && (CONFIG_RT_FRAMEWORK_INT_LEVEL == 1)
  return up_irq_level_save(CONFIG_RT_FRAMEWORK_MAX_TP_INT_LEVEL);
#else
  return up_irq_save();
#endif
}

/****************************************************************************
 * Name: up_interrupt_context
 *
 * Description:
 *   Return true is we are currently executing in the interrupt
 *   handler context.
 *
 ****************************************************************************/

#define up_interrupt_context() (up_current_regs() != NULL)

#undef EXTERN
#ifdef __cplusplus
}
#endif
#endif

#endif /* __ARCH_RH850_INCLUDE_IRQ_H */
