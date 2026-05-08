/****************************************************************************
 * arch/rh850/src/common/rh850_doirq.c
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <assert.h>

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/board.h>
#include <arch/board/board.h>
#include <sched/sched.h>

#include "rh850_internal.h"
#include "group/group.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Data
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
uint32_t g_nestlevel = 0;
uint32_t *rh850_doirq(int irq, uint32_t * regs)
{
  irqstate_t flags;
  /* Current regs non-zero indicates that we are processing an interrupt;
   * regs holds the state of the interrupted logic; current_regs holds the
   * state of the interrupted user task.  current_regs should, therefore,
   * only be modified for outermost interrupt handler (when g_nestlevel == 0)
   */
  flags = up_irq_save();
  if (g_nestlevel == 0)
    {
      up_set_current_regs(regs);
      g_running_tasks[this_cpu()] = this_task();
    }
  g_nestlevel++;
  up_irq_restore(flags);

  

  /* Deliver the IRQ */
  irq_dispatch(irq, regs);

  /* Context switches are indicated by the returned value of this function.
   * If a context switch occurred while processing the interrupt then
   * current_regs may have change value.  If we return any value different
   * from the input regs, then the lower level will know that a context
   * switch occurred during interrupt processing.  Context switching should
   * only be performed when the outermost interrupt handler returns.
   */
  __asm__ volatile ("synce");
  flags = up_irq_save();
  g_nestlevel--;
  if (g_nestlevel == 0)
  {
    regs = up_current_regs();
    up_set_current_regs(NULL);

    up_set_contexthdl(this_task()->contexthdl);
  }

  /* If a context switch occurred while processing the interrupt then
   * current_regs may have change value.  If we return any value different
   * from the input regs, then the lower level will know that a context
   * switch occurred during interrupt processing.
   */

  board_autoled_off(LED_INIRQ);

  return regs;
}


uint32_t *rh850_switch_context(uint32_t * oldregs)
{
  /* Yes, then we have to do things differently.
  * Just copy the current_regs into the OLD rtcb.
  */

  g_running_tasks[this_cpu()]->xcp.regs = oldregs;
  nxsched_suspend_scheduler(g_running_tasks[this_cpu()]);

  /* Update scheduler parameters */

  /* Then switch contexts.  Any necessary address environment
  * changes will be made when the interrupt returns.
  */
  nxsched_resume_scheduler(this_task());

  g_running_tasks[this_cpu()] = this_task();
  up_set_contexthdl(this_task()->contexthdl);
  
  return this_task()->xcp.regs;
}

uint32_t *up_regs(void)
{
  return this_task()->xcp.regs;
}
