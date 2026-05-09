/****************************************************************************
 * arch/rh850/src/common/rh850_switchcontext.c
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

#include <sched.h>
#include <assert.h>
#include <debug.h>

#include <nuttx/addrenv.h>
#include <nuttx/arch.h>
#include <nuttx/sched.h>

#include "sched/sched.h"
#include "clock/clock.h"
#include "rh850_internal.h"

/****************************************************************************
 * Static Functions
 ****************************************************************************/
static inline uint32_t __getIPSR();

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_switch_context
 *
 * Description:
 *   A task is currently in the ready-to-run list but has been prepped
 *   to execute. Restore its context, and start execution.
 *
 * Input Parameters:
 *   tcb: Refers to the head task of the ready-to-run list
 *     which will be executed.
 *   rtcb: Refers to the running task which will be blocked.
 *
 ****************************************************************************/

void up_switch_context(struct tcb_s *tcb, struct tcb_s *rtcb)
{
  /* Are we in an interrupt handler? */
  if (up_current_regs())
    {
      /* Then switch contexts.  Any necessary address environment
       * changes will be made when the interrupt returns.
       */

      up_set_current_regs(tcb->xcp.regs); // <=== Keep 

    }

  /* No, then we will need to perform the user context switch */

  /* We are not in an interrupt handler.  Copy the user C context
   * into the TCB of the task that was previously active.  if
   * up_saveusercontext returns a non-zero value, then this
   * is really the previously running task restarting!
   */

  else
  {
    while(0 != __getIPSR());     /* Wait until all current interrupts 
                                    released before entering TRAP */
    __asm__ volatile ("trap 0"); ///< Switch context via trap
  }
}

/* Return the current interrupt priority presenting */
static inline uint32_t __getIPSR()
{
    uint32_t result;
    __asm__ volatile ("stsr 10, %0, 2" : "=r" (result) :: "memory");
    return result;
}