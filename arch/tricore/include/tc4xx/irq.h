/****************************************************************************
 * arch/tricore/include/tc4xx/irq.h
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

#ifndef __ARCH_TRICORE_INCLUDE_TC4XX_IRQ_H
#define __ARCH_TRICORE_INCLUDE_TC4XX_IRQ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <IfxCpu_Intrinsics.h>

/****************************************************************************
 * Pre-processor Prototypes
 ****************************************************************************/

/* Upper CSA */

#define REG_UPCXI        0
#define REG_PSW          1
#define REG_A10          2
#define REG_UA11         3
#define REG_D8           4
#define REG_D9           5
#define REG_D10          6
#define REG_D11          7
#define REG_A12          8
#define REG_A13          9
#define REG_A14          10
#define REG_A15          11
#define REG_D12          12
#define REG_D13          13
#define REG_D14          14
#define REG_D15          15

/* Lower CSA */

#define REG_LPCXI        0
#define REG_LA11         1
#define REG_A2           2
#define REG_A3           3
#define REG_D0           4
#define REG_D1           5
#define REG_D2           6
#define REG_D3           7
#define REG_A4           8
#define REG_A5           9
#define REG_A6           10
#define REG_A7           11
#define REG_D4           12
#define REG_D5           13
#define REG_D6           14
#define REG_D7           15

#define REG_RA           REG_UA11
#define REG_SP           REG_A10
#define REG_UPC          REG_UA11

#define REG_LPC          REG_LA11

#define TC_CONTEXT_REGS  (16)
#define TC_CONTEXT_SIZE  (sizeof(void *) * TC_CONTEXT_REGS)

#define XCPTCONTEXT_REGS (TC_CONTEXT_REGS * 2)
#define XCPTCONTEXT_SIZE (sizeof(void *) * XCPTCONTEXT_REGS)

#ifdef CONFIG_RT_FRAMEWORK
#include <arch/tc4xx/atomic.h>
#include <arch/tc4xx/mpu.h>
#endif /* CONFIG_RT_FRAMEWORK */

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__
struct xcptcontext
{
  /* These are saved copies of the context used during
   * signal processing.
   */

  uintptr_t *saved_regs;

  /* Register save area with XCPTCONTEXT_SIZE, only valid when:
   * 1.The task isn't running or
   * 2.The task is interrupted
   * otherwise task is running, and regs contain the stale value.
   */

  uintptr_t *regs;
};

#ifdef CONFIG_RT_FRAMEWORK_SYSCALL
bool up_is_privilege_mode(void);
uint8_t up_get_mpu_set(void);

/* called directly */

static inline_function void up_set_privilege_to_user(void)
{
	uintptr_t psw;

	psw = (uintptr_t)__mfcr(TRICORE_CPU_PSW);
	psw &= ~(PSW_IO_USER0 | PSW_IO_USER1 | PSW_IO_SUPERVISOR);
	psw |= PSW_IO_USER0;
	__mtcr(TRICORE_CPU_PSW, psw);
	__isync();
}

/*called by trap*/

static inline_function void up_syscall_set_enter_int_state(uint32_t *regs)
{
	uintptr_t icr;
	uintptr_t pcxi;
	uintptr_t *plcsa, *pucsa;

	__dsync();

	plcsa = CSA_TO_ADDR(regs[REG_UPCXI]);
	pcxi = plcsa[REG_LPCXI];
	pucsa = CSA_TO_ADDR(pcxi);

#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
	__asm volatile("mov.a  a10, %0" ::"d"(pucsa[REG_A10]) : "a10");
#else
	__setareg(a10, pucsa[REG_A10]);
#endif
	icr = (uintptr_t)__mfcr(TRICORE_CPU_ICR);

#ifdef CONFIG_RT_FRAMEWORK_INT_LEVEL
	icr &= (~ICR_CCPN_MASK);
	icr |= ((pcxi & PCXI_PCPN_MASK) >> PCXI_PCPN_BIT);
#endif
	icr &= (~ICR_IE_MASK);
	icr |= ((pcxi & PCXI_PIE_MASK) >> PCXI_PIE_BIT << ICR_IE);

	__mtcr(TRICORE_CPU_ICR, icr);
	__isync();
}

static inline_function void up_syscall_set_exit_int_state(uint32_t *regs)
{

}

static inline_function bool up_syscall_get_prev_privilege(uint32_t *regs)
{
	uintptr_t *plcsa;
	uintptr_t *pucsa;

	plcsa = CSA_TO_ADDR(regs[REG_UPCXI]);

	__dsync();

	pucsa = CSA_TO_ADDR(plcsa[REG_LPCXI]);

	return ((pucsa[REG_PSW] & PSW_IO_SUPERVISOR) != 0) ? true : false;
}

static inline_function void up_syscall_set_prev_privilege(uint32_t *regs, const bool is_privilege)
{
	uintptr_t *plcsa;
	uintptr_t *pucsa;

	plcsa = CSA_TO_ADDR(regs[REG_UPCXI]);

	__dsync();

	pucsa = CSA_TO_ADDR(plcsa[REG_LPCXI]);

	pucsa[REG_PSW] &= ~(PSW_IO_USER0 | PSW_IO_USER1 | PSW_IO_SUPERVISOR);
	pucsa[REG_PSW] |= (is_privilege == true) ? PSW_IO_SUPERVISOR : PSW_IO_USER0;

}

static inline_function void up_syscall_set_prev_int_state(uint32_t *regs)
{
	uintptr_t icr;
	uintptr_t icr_ie;
	uintptr_t pcxi;
	uintptr_t *plcsa;

	icr = (uintptr_t)__mfcr(TRICORE_CPU_ICR);
	plcsa = CSA_TO_ADDR(regs[REG_UPCXI]);

	__dsync();

	pcxi = plcsa[REG_LPCXI];

	pcxi &= ~PCXI_PIE_MASK;
	icr_ie = (icr & ICR_IE_MASK) >> ICR_IE;
	pcxi |= icr_ie << PCXI_PIE_BIT;

#ifdef CONFIG_RT_FRAMEWORK_INT_LEVEL
	pcxi &= ~PCXI_PCPN_MASK;
	pcxi |= ((icr & ICR_CCPN_MASK) >> ICR_CCPN) << PCXI_PCPN_BIT;
#endif

	plcsa[REG_LPCXI] = pcxi;
}

#endif /* CONFIG_RT_FRAMEWORK_SYSCALL */

#endif /* __ASSEMBLY__ */

#endif /* __ARCH_TRICORE_INCLUDE_TC3XX_IRQ_H */
