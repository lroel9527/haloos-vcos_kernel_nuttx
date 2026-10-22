/****************************************************************************
 * drivers/note/notearti_driver.c
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
#include <sched.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <poll.h>

#include <nuttx/spinlock.h>
#include <nuttx/arch.h>
#include <nuttx/sched.h>
#include <nuttx/sched_note.h>
#include <nuttx/kmalloc.h>
#include <nuttx/note/note_driver.h>
#include <nuttx/note/notearti_driver.h>
#include <nuttx/panic_notifier.h>
#include <nuttx/fs/fs.h>
#include <nuttx/streams.h>

#if defined CONFIG_ARTI_ENABLED
#include "rtfw_arti.h"
#endif

#ifdef CONFIG_SCHED_INSTRUMENTATION_SYSCALL
#  ifdef CONFIG_LIB_SYSCALL
#    include <syscall.h>
#  else
#    define CONFIG_LIB_SYSCALL
#    include <syscall.h>
#    undef CONFIG_LIB_SYSCALL
#  endif
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define NCPUS CONFIG_BMP_NCPUS

/* Renumber idle task PIDs
 *  In NuttX, PID number less than NCPUS are idle tasks.
 *  In Linux, there is only one idle task of PID 0.
 */

#define get_pid(pid) ((pid) < NCPUS ? 0 : (pid))

#define get_task_state(s)                                                    \
  ((s) == 0 ? 'X' : ((s) <= LAST_READY_TO_RUN_STATE ? 'R' : 'S'))

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct notearti_driver_s
{
  struct note_driver_s driver;
  spinlock_t lock;
};


/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/
static void notearti_start(FAR struct note_driver_s *drv, FAR struct tcb_s *tcb);
static void notearti_stop(FAR struct note_driver_s *drv, FAR struct tcb_s *tcb);
#ifdef CONFIG_SCHED_INSTRUMENTATION_SWITCH
static void notearti_suspend(FAR struct note_driver_s *drv, FAR struct tcb_s *tcb);
static void notearti_resume(FAR struct note_driver_s *drv, FAR struct tcb_s *tcb);
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_WAKEUP
static void notearti_wakeup(FAR struct note_driver_s *drv,
                            FAR struct tcb_s *tcb, pid_t wakeup_id);
#endif

#ifdef CONFIG_SCHED_INSTRUMENTATION_SYSCALL
static void notearti_syscall_enter(FAR struct note_driver_s *drv,
                             int nr, int argc, va_list *ap);
static void notearti_syscall_leave(FAR struct note_driver_s *drv,
                             int nr, uintptr_t result);
#endif

#ifdef CONFIG_SCHED_INSTRUMENTATION_IRQHANDLER
static void notearti_irqhandler(FAR struct note_driver_s *drv, int irq,
                          FAR void *handler, bool enter);
#endif


/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct note_driver_ops_s g_notearti_ops =
{
	NULL,                      /* add */
	notearti_start,           /* start */
	notearti_stop,              /* stop */
#ifdef CONFIG_SCHED_INSTRUMENTATION_SWITCH
	notearti_suspend,         /* suspend */
	notearti_resume,          /* resume */
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_WAKEUP
	notearti_wakeup,          /* wakeup */
#endif
#ifdef CONFIG_SMP
	NULL,   /* cpu_start */
	NULL,   /* cpu_started */
#  ifdef CONFIG_SCHED_INSTRUMENTATION_SWITCH
	NULL,   /* cpu_pause */
	NULL,    /* cpu_paused */
	NULL,    /* cpu_resume */
	NULL,   /* cpu_resumed */
#  endif
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_PREEMPTION
	NULL,   /* premption */
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_CSECTION
	NULL,   /* csection */
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_SPINLOCKS
	NULL,   /* spinlock */
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_SYSCALL
	notearti_syscall_enter,   /* syscall_enter */
	notearti_syscall_leave,   /* syscall_leave */
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_IRQHANDLER
	notearti_irqhandler,      /* irqhandler */
#endif

};

/****************************************************************************
 * Public Data
 ****************************************************************************/

struct notearti_driver_s g_notearti_driver =
{
  {
#ifdef CONFIG_SCHED_INSTRUMENTATION_FILTER
    "arti",
    {
      {
        CONFIG_SCHED_INSTRUMENTATION_FILTER_DEFAULT_MODE,
#  ifdef CONFIG_SMP
        CONFIG_SCHED_INSTRUMENTATION_CPUSET
#  endif
      },
    },
#endif
    &g_notearti_ops
  }
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/


static void notearti_start(FAR struct note_driver_s *drv, FAR struct tcb_s *tcb)
{
  (void)drv; (void)tcb;
}
static void notearti_stop(FAR struct note_driver_s *drv, FAR struct tcb_s *tcb)
{
  (void)drv; (void)tcb;
}
#ifdef CONFIG_SCHED_INSTRUMENTATION_SWITCH
static void notearti_suspend(FAR struct note_driver_s *drv, FAR struct tcb_s *tcb)
{
  (void)drv;
  #if defined CONFIG_ARTI_ENABLED
  rtfw_arti_task_suspend(tcb);
  #endif
}
static void notearti_resume(FAR struct note_driver_s *drv, FAR struct tcb_s *tcb)
{
  (void)drv;
  #if defined CONFIG_ARTI_ENABLED
  rtfw_arti_task_resume(tcb);
  #endif
}
#endif

#ifdef CONFIG_SCHED_INSTRUMENTATION_WAKEUP
static void notearti_wakeup(FAR struct note_driver_s *drv,
                            FAR struct tcb_s *tcb, pid_t wakeup_id)
{
  FAR struct tcb_s *wakeup_tcb = nxsched_get_tcb(wakeup_id);

  #if defined CONFIG_ARTI_ENABLED
  rtfw_arti_task_wakeup(wakeup_tcb);
  #endif

  (void)drv;
  (void)tcb;
}
#endif


#ifdef CONFIG_SCHED_INSTRUMENTATION_SYSCALL
static void notearti_syscall_enter(FAR struct note_driver_s *drv,
                             int nr, int argc, va_list *ap)
{
}
static void notearti_syscall_leave(FAR struct note_driver_s *drv,
                             int nr, uintptr_t result)
{
}
#endif

#ifdef CONFIG_SCHED_INSTRUMENTATION_IRQHANDLER
static void notearti_irqhandler(FAR struct note_driver_s *drv, int irq,
                          FAR void *handler, bool enter)
{
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int notearti_initialize(void)
{
  uint32_t core_id;

  if (up_cpu_index() == 0)
    {
      for (core_id = 0; core_id < NCPUS; core_id++)
        {
          uint32_t task_id =
            rtfw_arti_get_configured_task_count() + core_id;

          rtfw_arti_set_current_task_id(core_id, task_id);
          rtfw_arti_set_task_resume_reason_by_id(
            core_id, task_id, RTFW_ARTI_TASK_RESUME_NONE);
        }

    }

  return OK;
}
