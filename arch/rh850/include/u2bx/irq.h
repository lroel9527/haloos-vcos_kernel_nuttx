/****************************************************************************
 * arch/renesas/include/u2bx/irq.h
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

#ifndef __ARCH_RH850_INCLUDE_U2BX_IRQ_H
#define __ARCH_RH850_INCLUDE_U2BX_IRQ_H

#include <nuttx/config.h>
#include <stdint.h>
#include <arch/syscall.h>



#define RH850_NVECTORS             (1024)
#define NR_IRQS                    (1024)

#define RH850_PSW_ID_MASK      (1<<5)


/* Register information */
// RH850 G4MH
#define REG_FPEPC (0)
#define REG_FPSR  (1)
#define REG_CTPC  (2)
#define REG_CTPSW (3)
#define REG_EIIC  (4)
#define REG_EIPC  (5)
#define REG_EIPSW (6)
#define REG_LP    (7)  // << REG_R31
#define REG_R2    (8)
#define REG_R1    (9)
#define REG_R30   (10)
#define REG_R29   (11)
#define REG_R28   (12)
#define REG_R27   (13)
#define REG_R26   (14)
#define REG_R25   (15)
#define REG_R24   (16)
#define REG_R23   (17)
#define REG_R22   (18)
#define REG_R21   (19)
#define REG_R20   (20)
#define REG_R19   (21)
#define REG_R18   (22)
#define REG_R17   (23)
#define REG_R16   (24)
#define REG_R15   (25)
#define REG_R14   (26)
#define REG_R13   (27)
#define REG_R12   (28)
#define REG_R11   (29)
#define REG_R10   (30)
#define REG_R9    (31)
#define REG_R8    (32)
#define REG_R7    (33)
#define REG_R6    (34)


#define REG_PC REG_EIPC


#define XCPTCONTEXT_REGS        (35)
#define XCPTCONTEXT_SIZE        (4 * XCPTCONTEXT_REGS)


#ifndef __ASSEMBLY__
struct xcptcontext
{
  /* Register save area */
  uint32_t * regs;
};

/* Name: up_irq_save, up_irq_restore, and friends.
 *
 * NOTE: This function should never be called from application code and,
 * as a general rule unless you really know what you are doing, this
 * function should not be called directly from operation system code either:
 * Typically, the wrapper functions, enter_critical_section() and
 * leave_critical section(), are probably what you really want.
 */


/* Return the current interrupt enable state and disable IRQs */
int up_timer_value(clock_t *ticks);

/* Return the current value of the stack pointer */

static inline uint32_t up_getsp(void)
{
  uint32_t sp;

    __asm__ volatile (
        "mov r3, %0"
        : "=r"(sp)
        :
        : "memory"
    );

  return sp;
}

/* Disable interrupts */

static inline void up_irq_disable(void)
{
  __DI();
}

/* Enable interrupts */

static inline void up_irq_enable(void)
{
  __EI();
}

/* Return the current interrupt enable state and disable interrupts */
static inline uint32_t __getPSW()
{
    uint32_t result;
    __asm__ volatile ("stsr 5, %0, 0" : "=r" (result) :: "memory");
    return result;
}
static inline irqstate_t up_irq_save(void)
{
  irqstate_t ret = (irqstate_t) (__getPSW() & RH850_PSW_ID_MASK);
  ret = (ret >> 5);
  up_irq_disable();
  return ret;
}

/* Restore saved interrupt state */
static inline void up_irq_restore(irqstate_t flags)
{
  if (0 == (flags))
  {
    up_irq_enable();
  }
  else
  {
    up_irq_disable();
  }
}
#endif /* __ASSEMBLY__ */

int up_timer_value(clock_t *ticks);


/****************************************************************************
 * Name: up_getusrpc
 ****************************************************************************/

#define up_getusrpc(regs) \
    (((uint32_t *)((regs) ? (regs) : up_current_regs()))[REG_PC])

#endif /* __ARCH_RH850_INCLUDE_U2BX_IRQ_H */