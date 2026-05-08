/****************************************************************************
 * arch/arm/src/arm/arm_initialstate.c
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
#include <string.h>

#include <nuttx/arch.h>


#if CONFIG_BSP_FSP_SUPPORT
#include "bsp_api.h"
#else
#include "Device_common.h"
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

 /* Macros required to set up the initial stack. */
#define STACK_INITIAL_VALUE_R1          ((uint32_t) 0x01010101)
#define STACK_INITIAL_VALUE_R2          ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x02)
#define STACK_INITIAL_VALUE_R3          ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x03)
#define STACK_INITIAL_VALUE_R4          ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x04)
#define STACK_INITIAL_VALUE_R5          ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x05)
#define STACK_INITIAL_VALUE_R6          ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x06)
#define STACK_INITIAL_VALUE_R7          ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x07)
#define STACK_INITIAL_VALUE_R8          ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x08)
#define STACK_INITIAL_VALUE_R9          ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x09)
#define STACK_INITIAL_VALUE_R10         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x10)
#define STACK_INITIAL_VALUE_R11         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x11)
#define STACK_INITIAL_VALUE_R12         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x12)
#define STACK_INITIAL_VALUE_R13         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x13)
#define STACK_INITIAL_VALUE_R14         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x14)
#define STACK_INITIAL_VALUE_R15         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x15)
#define STACK_INITIAL_VALUE_R16         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x16)
#define STACK_INITIAL_VALUE_R17         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x17)
#define STACK_INITIAL_VALUE_R18         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x18)
#define STACK_INITIAL_VALUE_R19         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x19)
#define STACK_INITIAL_VALUE_R20         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x20)
#define STACK_INITIAL_VALUE_R21         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x21)
#define STACK_INITIAL_VALUE_R22         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x22)
#define STACK_INITIAL_VALUE_R23         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x23)
#define STACK_INITIAL_VALUE_R24         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x24)
#define STACK_INITIAL_VALUE_R25         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x25)
#define STACK_INITIAL_VALUE_R26         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x26)
#define STACK_INITIAL_VALUE_R27         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x27)
#define STACK_INITIAL_VALUE_R28         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x28)
#define STACK_INITIAL_VALUE_R29         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x29)
#define STACK_INITIAL_VALUE_R30         ((uint32_t) STACK_INITIAL_VALUE_R1 * 0x30)
#define INITIAL_PSW_MASK            (0x00078000)
/* Hardware specific macros */
#define REGISTER_SEL_0    0
#define PSW_REGISTER_ID          (5)
#define FPSR_REGISTER_ID         (6)
#define FXSR_REGISTER_ID         (6)
#define FXSR_REGISTER_SEL        (10)

#define CURRENT_PSW_VALUE        (__STSR(PSW_REGISTER_ID, REGISTER_SEL_0))

/****************************************************************************
 * Name: up_initial_state
 *
 * Description:
 *   A new thread is being started and a new TCB
 *   has been created. This function is called to initialize
 *   the processor specific portions of the new TCB.
 *
 *   This function must setup the initial architecture registers
 *   and/or  stack so that execution will begin at tcb->start
 *   on the next context switch.
 *
 ****************************************************************************/

static uint8_t g_idle_stack_buffer[CONFIG_IDLETHREAD_STACKSIZE];
const uintptr_t g_idle_topstack =
    (uintptr_t)(g_idle_stack_buffer + CONFIG_IDLETHREAD_STACKSIZE);
 void up_initial_state(struct tcb_s *tcb)
{
  struct xcptcontext *xcp  = &tcb->xcp;

    if (tcb->pid == IDLE_PROCESS_ID)
    {
      char *stack_ptr = (char *)(g_idle_topstack);
#ifdef CONFIG_STACK_COLORATION
      char *stack_end = (char *)up_getsp();

      /* If stack debug is enabled, then fill the stack with a
       * recognizable value that we can use later to test for high
       * water marks.
       */

      while (stack_ptr < stack_end)
        {
          *--stack_end = 0xaa;
        }
#endif /* CONFIG_STACK_COLORATION */

      tcb->stack_alloc_ptr = stack_ptr;
      tcb->stack_base_ptr  = stack_ptr;
      tcb->adj_stack_size  = CONFIG_IDLETHREAD_STACKSIZE;
    }

      /* Initialize the context registers to stack top */

  xcp->regs = (void *)((uint32_t)tcb->stack_base_ptr +
                                 tcb->adj_stack_size -
                                 XCPTCONTEXT_SIZE);
  /* Initialize the initial exception register context structure */
  xcp->regs[REG_R6]  = STACK_INITIAL_VALUE_R6;
  xcp->regs[REG_R7]  = STACK_INITIAL_VALUE_R7;
  xcp->regs[REG_R8]  = STACK_INITIAL_VALUE_R8;
  xcp->regs[REG_R9]  = STACK_INITIAL_VALUE_R9;
  xcp->regs[REG_R10] = STACK_INITIAL_VALUE_R10;
  xcp->regs[REG_R11] = STACK_INITIAL_VALUE_R11;
  xcp->regs[REG_R12] = STACK_INITIAL_VALUE_R12;
  xcp->regs[REG_R13] = STACK_INITIAL_VALUE_R13;
  xcp->regs[REG_R14] = STACK_INITIAL_VALUE_R14;
  xcp->regs[REG_R15] = STACK_INITIAL_VALUE_R15;
  xcp->regs[REG_R16] = STACK_INITIAL_VALUE_R16;
  xcp->regs[REG_R17] = STACK_INITIAL_VALUE_R17;
  xcp->regs[REG_R18] = STACK_INITIAL_VALUE_R18;
  xcp->regs[REG_R19] = STACK_INITIAL_VALUE_R19;
  xcp->regs[REG_R20] = STACK_INITIAL_VALUE_R20;
  xcp->regs[REG_R21] = STACK_INITIAL_VALUE_R21;
  xcp->regs[REG_R22] = STACK_INITIAL_VALUE_R22;
  xcp->regs[REG_R23] = STACK_INITIAL_VALUE_R23;
  xcp->regs[REG_R24] = STACK_INITIAL_VALUE_R24;
  xcp->regs[REG_R25] = STACK_INITIAL_VALUE_R25;
  xcp->regs[REG_R26] = STACK_INITIAL_VALUE_R26;
  xcp->regs[REG_R27] = STACK_INITIAL_VALUE_R27;
  xcp->regs[REG_R28] = STACK_INITIAL_VALUE_R28;
  xcp->regs[REG_R29] = STACK_INITIAL_VALUE_R29;
  xcp->regs[REG_R30] = STACK_INITIAL_VALUE_R30;
  xcp->regs[REG_R1] = STACK_INITIAL_VALUE_R1;
  xcp->regs[REG_R2] = STACK_INITIAL_VALUE_R2;
  xcp->regs[REG_LP]  = 0x00000000;

  /* Keep System pre-configuration (HV, CUx, EBV) as current setting in PSW register */
  xcp->regs[REG_EIPSW]  = (CURRENT_PSW_VALUE & INITIAL_PSW_MASK);
  xcp->regs[REG_EIPC] = (uint32_t)tcb->start;
  xcp->regs[REG_EIIC] = 0x00000000;
  xcp->regs[REG_CTPSW] = (CURRENT_PSW_VALUE & INITIAL_PSW_MASK);
  xcp->regs[REG_CTPC] = 0x00000000;
  xcp->regs[REG_FPSR] = 0x00000000;
  xcp->regs[REG_FPEPC] = 0x00000000;
}
