/****************************************************************************
 * arch/rh850/src/common/rh850_initialize.c
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/arch.h>
#include <nuttx/board.h>
#include <arch/board/board.h>

#include <nuttx/kmalloc.h>
#include <nuttx/hrtimer.h>
#include <nuttx/timers/oneshot.h>
#include <nuttx/timers/arch_alarm.h>

#include <arch/irq.h>
#include "rh850_internal.h"

#if CONFIG_BSP_FSP_SUPPORT
#include "bsp_api.h"
#else
#include "Device_common.h"
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/

#define OSTM_EIC_ADDR (0xfff802d0)
#define OSTMCMP_ADDR (0xffbf0000)
#define OSTMCNT_ADDR (0xffbf0004)
#define OSTMCTL_ADDR (0xffbf0020)
#define OSTMTS_ADDR (0xffbf0014)
#define OSTMTT_ADDR (0xffbf0018)

/* OSTM Count Start Trigger Register (OSTMnTS) */
#define OSTM_COUNTER_START (0x01U) /* Starts the counter */

/* OSTM Count Stop Trigger Register (OSTMnTT) */
#define OSTM_COUNTER_STOP (0x01U) /* Stops the counter */

/* OSTM Control Register (OSTMnCTL) */
#define OSTM_MODE_INTERVAL_TIMER (0x00U)
#define OSTM_MODE_FREE_RUNNING (0x02U)

/* Disables or Enable the interrupts when counting starts */
#define OSTM_START_INTERRUPT_DISABLE (0x00U)
#define OSTM_START_INTERRUPT_ENABLE (0x01U)

/* Enable OSTM Interrupt*/
#define OSTM_INTERRUPT_ENABLE (0x80U)

/* Interrupt vector method select (TBxxx) */
#define INT_DIRECT_VECTOR (0x00U)
#define INT_TABLE_VECTOR (0x40U)

#ifndef CONFIG_TIMER_INT_PRIORITY
#define CONFIG_TIMER_INT_PRIORITY (15)
#endif

#ifndef CONFIG_TIMER_CLOCK_HZ
#define CONFIG_TIMER_CLOCK_HZ (80000000)
#endif

#ifndef CONFIG_TICK_RATE_HZ
#define CONFIG_TICK_RATE_HZ (1000)
#endif

#ifndef CONFIG_IRQ_OSTM
#define CONFIG_IRQ_OSTM 360
#endif
/**
 * @brief   Execute dummy read and syncp for EIC register
 * @details Dummy read on the register and SYNCP
 * @param [in]    reg   Pointer to register address
 */
#define BSP_INT_IOREG_DUMMY_READ_SYNCP(reg) \
  do                                        \
  {                                         \
    volatile uint32_t dummy = (reg);        \
    SYNCP();                                \
    (void)dummy;                            \
  } while (0)

struct rh850_timer_s
{
  uint32_t frequency;      /* Frequency of the timer */
  uint32_t cout_per_cycle; /* Counter counts per OS tick */
  uint64_t cycles;         /* Total cycles since timer start */
  uint64_t ticks;          /* Total ticks since timer start */
};

static struct rh850_timer_s g_timer;

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static uint64_t current_usec(void)
{
  uint64_t ticks, us;

  // get total ticks
#if defined(CONFIG_RT_FRAMEWORK) && (CONFIG_RT_FRAMEWORK == 1)
  ticks = g_timer.ticks + (uint64_t)getreg32(OSTMCNT_ADDR);
#else
  ticks = ((uint64_t)g_timer.cycles * g_timer.cout_per_cycle) + (uint64_t)getreg32(OSTMCNT_ADDR);
#endif

  // compute microseconds
  us = (ticks / g_timer.frequency) * USEC_PER_SEC;

  return us;
}

#if defined(CONFIG_RT_FRAMEWORK) && (CONFIG_RT_FRAMEWORK == 1)
/****************************************************************************
 * Name: up_systick_isr_handler
 *
 * Returned Value:
 *   Always returns OK
 *
 ****************************************************************************/
void up_systick_isr_handler(void)
{
  g_timer.ticks += (uint64_t)getreg32(OSTMCMP_ADDR);
}
#else
/****************************************************************************
 * Function:  rh850_timerisr
 *
 * Description:
 *   The timer ISR will perform a variety of services for various ions
 *   of the systems.
 *
 ****************************************************************************/
static int rh850_timerisr(int irq, uint32_t *regs, void *arg)
{
  g_timer.cycles++;

  /* Process timer interrupt */
  nxsched_process_timer();

  return OK;
}
 #endif


static clock_t rh850_hrtimer_current(struct hrtimer_queue_s *queue);
static void rh850_hrtimer_set_expire(struct hrtimer_queue_s *queue, clock_t value);
static void rh850_hrtimer_start(struct hrtimer_queue_s *queue);
static void rh850_hrtimer_trigger(struct hrtimer_queue_s *queue);

static const struct hrtimer_ops_s g_rh850_hrtimer_ops = {
    .current = rh850_hrtimer_current,
    .set_expire = rh850_hrtimer_set_expire,
    .start = rh850_hrtimer_start,
    .trigger = rh850_hrtimer_trigger,
};

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function:  up_timer_initialize
 *
 * Description:
 *   This function is called during start-up to initialize the timer
 *   interrupt.
 *
 ****************************************************************************/
void up_timer_initialize(void)
{
  volatile uint16_t *pulOSTMIntReg;
  g_timer.frequency = CONFIG_TIMER_CLOCK_HZ;
  g_timer.cout_per_cycle = (CONFIG_TIMER_CLOCK_HZ / USEC_PER_SEC) * USEC_PER_TICK - 1;

  /* Set OSTM control setting
   * Used as system timer and uptime source.
   */
  *((volatile uint32_t *)OSTMCTL_ADDR) =
      (OSTM_INTERRUPT_ENABLE | OSTM_MODE_INTERVAL_TIMER | OSTM_START_INTERRUPT_DISABLE);
  *((volatile uint32_t *)OSTMCMP_ADDR) = g_timer.cout_per_cycle - 1;

  /* Interrupt configuration for OSTM Timer */
#if defined(CONFIG_RT_FRAMEWORK) && (CONFIG_RT_FRAMEWORK == 1)
  up_hrtimer_set_ops(&g_rh850_hrtimer_ops);
#else
  /* Setup interrupt and enable */
  RH850_IRQ_SetPriority(CONFIG_IRQ_OSTM, CONFIG_TIMER_INT_PRIORITY);
  irq_attach(CONFIG_IRQ_OSTM, (xcpt_t)rh850_timerisr, NULL);
  up_enable_irq(CONFIG_IRQ_OSTM);
#endif

}

/****************************************************************************
 * Name: up_timer_gettime
 *
 * Description:
 *   Return the elapsed time since power-up (or, more correctly, since
 *   the architecture-specific timer was initialized).  This function is
 *   functionally equivalent to:
 *
 *      int clock_gettime(clockid_t clockid, FAR struct timespec *ts);
 *
 *   when clockid is CLOCK_MONOTONIC.
 *
 *   This function provides the basis for reporting the current time and
 *   also is used to eliminate error build-up from small errors in interval
 *   time calculations.
 *
 *   Provided by platform-specific code and called from the RTOS base code.
 *
 * Input Parameters:
 *   ts - Provides the location in which to return the up-time.
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 * Assumptions:
 *   Called from the normal tasking context.  The implementation must
 *   provide whatever mutual exclusion is necessary for correct operation.
 *   This can include disabling interrupts in order to assure atomic register
 *   operations.
 *
 ****************************************************************************/

int up_timer_gettime(FAR struct timespec *ts)
{
  uint64_t usec = current_usec();

  ts->tv_sec = usec / USEC_PER_SEC;
  ts->tv_nsec = (usec % USEC_PER_SEC) * NSEC_PER_USEC;

  return OK;
}

int up_timer_gettick(FAR clock_t *ticks)
{
  uint64_t usec = current_usec();

  *ticks = (clock_t)(usec / USEC_PER_TICK);

  return OK;
}

void up_timer_getmask(FAR clock_t *mask)
{
  *mask = UINT32_MAX;
  return;
}

int up_timer_value(FAR clock_t *ticks)
{
  uint64_t usec = current_usec();

  *ticks = (clock_t)(usec / USEC_PER_TICK);

  return OK;
}

uint32_t up_timer_freq(void)
{
  return 80000000;
}
static clock_t rh850_hrtimer_current(struct hrtimer_queue_s *queue)
{
  /* get OSTM ticks from boot */
  uint32_t cnt = getreg32(OSTMCNT_ADDR);

  return g_timer.ticks + (uint64_t)cnt;
}
static void rh850_hrtimer_set_expire(struct hrtimer_queue_s *queue, clock_t value)
{
  /* set OSTM compare value */
  uint64_t cmp = value - g_timer.ticks;
  putreg32((uint32_t)cmp, OSTMCMP_ADDR);
}

static void rh850_hrtimer_start(struct hrtimer_queue_s *queue)
{
  /* Enable OSTM operation */
  *((volatile uint32_t *)OSTMTT_ADDR) = OSTM_COUNTER_STOP;
  g_timer.ticks = 0;
  g_timer.cycles = 0;
  *((volatile uint32_t *)OSTMTS_ADDR) = OSTM_COUNTER_START;
}

static void rh850_hrtimer_trigger(struct hrtimer_queue_s *queue)
{
  /* Trigger OSTM interrupt */
  RH850_IRQ_GetActiveByPE((uint8_t) 0, (uint32_t) 360);
}
