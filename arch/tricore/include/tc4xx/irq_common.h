/****************************************************************************
 * arch/tricore/include/irq.h
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

/* This file should never be included directly but, rather, only indirectly
 * through nuttx/irq.h
 */

#ifndef __ARCH_TRICORE_INCLUDE_IRQ_H
#define __ARCH_TRICORE_INCLUDE_IRQ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <sys/types.h>
#ifndef __ASSEMBLY__
#  include <stdbool.h>
#ifdef CONFIG_RT_FRAMEWORK
#  include <arch/syscall.h>
#endif
#endif

/* Include NuttX-specific IRQ definitions */

#include <nuttx/irq.h>

/* Include chip-specific IRQ definitions (including IRQ numbers) */

#include <arch/chip/irq.h>

/****************************************************************************
 * Pre-processor Prototypes
 ****************************************************************************/
/* Tricore Customer ID Reg */
#define TRICORE_CPU_CUS_ID 0xFE50
/* Tricore Program Status Word Reg */
#define TRICORE_CPU_PSW 0xFE04
/* Tricore Previous Context Information Reg */
#define TRICORE_CPU_PCXI 0xFE00
/* Tricore Interrupt Control Reg */
#define TRICORE_CPU_ICR 0xFE2C
/* Tc3XX Program Counter Reg */
#define TRICORE_CPU_PC 0xFE08
/* Tricore Interrupt Stack Pointer*/
#define TRICORE_CPU_ISP 0xFE28
/* Tricore System Configuration Reg */
#define TRICORE_CPU_SYSCON 0xFE14
/* Tricore Data Protection Range 0, Lower Bound Register */
#define TRICORE_CPU_DPR0_L 0xC000
/* Tricore Data Protection Range 0, Upper Bound Register */
#define TRICORE_CPU_DPR0_U 0xC004
/* Tricore Data Protection Range 1, Lower Bound Register */
#define TRICORE_CPU_DPR1_L 0xC008
/* Tricore Data Protection Range 1, Upper Bound Register */
#define TRICORE_CPU_DPR1_U 0xC00C
/* Tricore Data Protection Range 2, Lower Bound Register */
#define TC3XX_CPU_DPR2_L 0xC010
/* Tricore Data Protection Range 2, Upper Bound Register */
#define TRICORE_CPU_DPR2_U 0xC014
/* Tricore Data Protection Range 3, Lower Bound Register */
#define TRICORE_CPU_DPR3_L 0xC018
/* Tricore Data Protection Range 3, Upper Bound Register */
#define TRICORE_CPU_DPR3_U 0xC01C
/* Tricore Data Protection Range 4, Lower Bound Register */
#define TRICORE_CPU_DPR4_L 0xC020
/* Tricore Data Protection Range 4, Upper Bound Register */
#define TRICORE_CPU_DPR4_U 0xC024
/* Tricore Data Protection Range 5, Lower Bound Register */
#define TRICORE_CPU_DPR5_L 0xC028
/* Tricore Data Protection Range 5, Upper Bound Register */
#define TRICORE_CPU_DPR5_U 0xC02C
/* Tricore Data Protection Range 6, Lower Bound Register */
#define TRICORE_CPU_DPR6_L 0xC030
/* Tricore Data Protection Range 6, Upper Bound Register */
#define TRICORE_CPU_DPR6_U 0xC034
/* Tricore Data Protection Range 7, Lower Bound Register */
#define TRICORE_CPU_DPR7_L 0xC038
/* Tricore Data Protection Range 7, Upper Bound Register */
#define TRICORE_CPU_DPR7_U 0xC03C
/* Tricore Data Protection Range 8, Lower Bound Register */
#define TRICORE_CPU_DPR8_L 0xC040
/* Tricore Data Protection Range 8, Upper Bound Register */
#define TRICORE_CPU_DPR8_U 0xC044
/* Tricore Data Protection Range 9, Lower Bound Register */
#define TRICORE_CPU_DPR9_L 0xC048
/* Tricore Data Protection Range 9, Upper Bound Register */
#define TRICORE_CPU_DPR9_U 0xC04C
/* Tricore Data Protection Range 10, Lower Bound Register */
#define TRICORE_CPU_DPR10_L 0xC050
/* Tricore Data Protection Range 10, Upper Bound Register */
#define TRICORE_CPU_DPR10_U 0xC054
/* Tricore Data Protection Range 11, Lower Bound Register */
#define TRICORE_CPU_DPR11_L 0xC058
/* Tricore Data Protection Range 11, Upper Bound Register */
#define TRICORE_CPU_DPR11_U 0xC05C
/* Tricore Data Protection Range 12, Lower Bound Register */
#define TRICORE_CPU_DPR12_L 0xC060
/* Tricore Data Protection Range 12, Upper Bound Register */
#define TRICORE_CPU_DPR12_U 0xC064
/* Tricore Data Protection Range 13, Lower Bound Register */
#define TRICORE_CPU_DPR13_L 0xC068
/* Tricore Data Protection Range 13, Upper Bound Register */
#define TRICORE_CPU_DPR13_U 0xC06C
/* Tricore Data Protection Range 14, Lower Bound Register */
#define TRICORE_CPU_DPR14_L 0xC070
/* Tricore Data Protection Range 14, Upper Bound Register */
#define TRICORE_CPU_DPR14_U 0xC074
/* Tricore Data Protection Range 15, Lower Bound Register */
#define TRICORE_CPU_DPR15_L 0xC078
/* Tricore Data Protection Range 15, Upper Bound Register */
#define TRICORE_CPU_DPR15_U 0xC07C
/* Tricore Data Protection Range 16, Lower Bound Register */
#define TRICORE_CPU_DPR16_L 0xC080
/* Tricore Data Protection Range 16, Upper Bound Register */
#define TRICORE_CPU_DPR16_U 0xC084
/* Tricore Data Protection Range 17, Lower Bound Register */
#define TRICORE_CPU_DPR17_L 0xC088
/* Tricore Data Protection Range 17, Upper Bound Register */
#define TRICORE_CPU_DPR17_U 0xC08C
/* Tricore Code Protection Range 0 Lower Bound Register */
#define TRICORE_CPU_CPR0_L 0xD000
/* Tricore Code Protection Range 0 Upper Bound Register */
#define TRICORE_CPU_CPR0_U 0xD004
/* Tricore Code Protection Range 1 Lower Bound Register */
#define TRICORE_CPU_CPR1_L 0xD008
/* Tricore Code Protection Range 1 Upper Bound Register */
#define TRICORE_CPU_CPR1_U 0xD00C
/* Tricore Code Protection Range 2 Lower Bound Register */
#define TRICORE_CPU_CPR2_L 0xD010
/* Tricore Code Protection Range 2 Upper Bound Register */
#define TRICORE_CPU_CPR2_U 0xD014
/* Tricore Code Protection Range 3 Lower Bound Register */
#define TRICORE_CPU_CPR3_L 0xD018
/* Tricore Code Protection Range 3 Upper Bound Register */
#define TRICORE_CPU_CPR3_U 0xD01C
/* Tricore Code Protection Range 4 Lower Bound Register */
#define TRICORE_CPU_CPR4_L 0xD020
/* Tricore Code Protection Range 4 Upper Bound Register */
#define TRICORE_CPU_CPR4_U 0xD024
/* Tricore Code Protection Range 5 Lower Bound Register */
#define TRICORE_CPU_CPR5_L 0xD028
/* Tricore Code Protection Range 5 Upper Bound Register */
#define TRICORE_CPU_CPR5_U 0xD02C
/* Tricore Code Protection Range 6 Lower Bound Register */
#define TRICORE_CPU_CPR6_L 0xD030
/* Tricore Code Protection Range 6 Upper Bound Register */
#define TRICORE_CPU_CPR6_U 0xD034
/* Tricore Code Protection Range 7 Lower Bound Register */
#define TRICORE_CPU_CPR7_L 0xD038
/* Tricore Code Protection Range 7 Upper Bound Register */
#define TRICORE_CPU_CPR7_U 0xD03C
/* Tricore Code Protection Range 8 Lower Bound Register */
#define TRICORE_CPU_CPR8_L 0xD040
/* Tricore Code Protection Range 8 Upper Bound Register */
#define TRICORE_CPU_CPR8_U 0xD044
/* Tricore Code Protection Range 9 Lower Bound Register */
#define TRICORE_CPU_CPR9_L 0xD048
/* Tricore Code Protection Range 9 Upper Bound Register */
#define TRICORE_CPU_CPR9_U 0xD04C
/* Tricore Code Protection Execute Enable Register Set 0 */
#define TRICORE_CPU_CPXE_0 0xE000
/* Tricore Code Protection Execute Enable Register Set 1 */
#define TRICORE_CPU_CPXE_1 0xE004
/* Tricore Code Protection Execute Enable Register Set 2 */
#define TRICORE_CPU_CPXE_2 0xE008
/* Tricore Code Protection Execute Enable Register Set 3 */
#define TRICORE_CPU_CPXE_3 0xE00C
/* Tricore Code Protection Execute Enable Register Set 4 */
#define TRICORE_CPU_CPXE_4 0xE040
/* Tricore Code Protection Execute Enable Register Set 5 */
#define TRICORE_CPU_CPXE_5 0xE044
/* Tricore Data Protection Read Enable Register Set 0 */
#define TRICORE_CPU_DPRE_0 0xE010
/* Tricore Data Protection Read Enable Register Set 1 */
#define TRICORE_CPU_DPRE_1 0xE014
/* Tricore Data Protection Read Enable Register Set 2 */
#define TRICORE_CPU_DPRE_2 0xE018
/* Tricore Data Protection Read Enable Register Set 3 */
#define TRICORE_CPU_DPRE_3 0xE01C
/* Tricore Data Protection Read Enable Register Set 4 */
#define TRICORE_CPU_DPRE_4 0xE050
/* Tricore Data Protection Read Enable Register Set 5 */
#define TRICORE_CPU_DPRE_5 0xE054
/* Tricore Data Protection Write Enable Register Set 0 */
#define TRICORE_CPU_DPWE_0 0xE020
/* Tricore Data Protection Write Enable Register Set 1 */
#define TRICORE_CPU_DPWE_1 0xE024
/* Tricore Data Protection Write Enable Register Set 2 */
#define TRICORE_CPU_DPWE_2 0xE028
/* Tricore Data Protection Write Enable Register Set 3 */
#define TRICORE_CPU_DPWE_3 0xE02C
/* Tricore Data Protection Write Enable Register Set 4 */
#define TRICORE_CPU_DPWE_4 0xE060
/* Tricore Data Protection Write Enable Register Set 5 */
#define TRICORE_CPU_DPWE_5 0xE064

/* PSW: Program Status Word Register */
#define PSW_CDE           (1 << 7) /* Bits 7: Call Depth Count Enable */
#define PSW_IS            (1 << 9) /* Bits 9: Interrupt Stack Control */
#define PSW_IO            (10)     /* Bits 10-11: Access Privilege Level Control (I/O Privilege) */
#define PSW_IO_USER0      (0 << PSW_IO)
#define PSW_IO_USER1      (1 << PSW_IO)
#define PSW_IO_SUPERVISOR (2 << PSW_IO)
#define PSW_GW            (1 << 8)
#define PSW_MPU_SET_PART0_OFFSET  (12U) /* Bits 12-13: Protection Register Set bits part0 */
#define PSW_MPU_SET_PART1_OFFSET  (15U) /* Bits 15: Protection Register Set bits part1*/
#define PSW_MPU_SET_PART0_MASK    (3 << PSW_MPU_SET_PART0_OFFSET)
#define PSW_MPU_SET_PART1_MASK    (1 << PSW_MPU_SET_PART1_OFFSET)
#define PSW_MPU_SET_PART0_VALUE(PSW)   (((PSW) & PSW_MPU_SET_PART0_MASK) >> PSW_MPU_SET_PART0_OFFSET)
#define PSW_MPU_SET_PART1_VALUE(PSW)   ((((PSW) & PSW_MPU_SET_PART1_MASK) >> PSW_MPU_SET_PART1_OFFSET) << 2U)

#define PSW_MPU_SET(PSW)  (PSW_MPU_SET_PART0_VALUE(PSW) + PSW_MPU_SET_PART1_VALUE(PSW))

/* PCXI: Previous Context Information and Pointer Register */
#define PCXI_UL         (1 << 20) /* Bits 20: Upper or Lower Context Tag */
#define PCXI_PIE        (1 << 21) /* Bits 21: Previous Interrupt Enable */
#define PCXI_PIE_BIT    (21) /* Bits 21: Previous Interrupt Enable */
#define PCXI_PIE_MASK   (1 << PCXI_PIE_BIT)
#define PCXI_PCPN_BIT    (22) /* Bits 22-29: Previous CPU Priority Number */
#define PCXI_PCPN_MASK   (0xff << PCXI_PCPN_BIT)

/* FCX: Free CSA List Head Pointer Register */
#define FCX_FCXO        (0)       /* Bits 0-15: FCX Offset Address */
#define FCX_FCXS        (16)      /* Bits 16-19: FCX Segment Address */
#define FCX_FCXO_MASK   (0xffff << FCX_FCXO)
#define FCX_FCXS_MASK   (0xf    << FCX_FCXS)
#define FCX_FREE        (FCX_FCXS_MASK | FCX_FCXO_MASK) /* Free CSA manipulation */

/* ICR: Interrupt Control Register */
#define ICR_IE          (15)         /* Bits 15: Global Interrupt Enable Bit */
#define ICR_PIPN        (16)         /* Bits 16-23: Pending Interrupt Priority Number */
#define ICR_CCPN        (0)          /* Bits 0-7: Current CPU Priority Number */

#define ICR_IE_MASK     (0x1 << ICR_IE)
#define ICR_PIPN_MASK   (0xff << ICR_PIPN)
#define ICR_CCPN_MASK   (0xff << ICR_CCPN)

/** Ifx CPUs register */
/** \brief 0x00000100, CPU_PSW_GW */
#define CPU_PSW_GW_MASK ( 0x00000100UL )    /* bit:8 */

#define CSA_TO_ADDR(csa) ((uintptr_t *)((((csa) & 0x000F0000) << 12) | (((csa) & 0x0000FFFF) << 6)))

#define NR_IRQS          (255)


/* Compatibility names used by the existing common TriCore port. */
#define TC3XX_CPU_CORE_ID 0xFE1C
#define TC3XX_CPU_CUS_ID 0xFE50
#define TX3XX_CPU_PSW 0xFE04
#define TC3XX_CPU_PCXI 0xFE00
#define TC3XX_CPU_ICR 0xFE2C
#define TC3XX_CPU_PC 0xFE08
#define TC3XX_CPU_ISP 0xFE28
#define TC3XX_CPU_SYSCON 0xFE14
#define TC3XX_CPU_DPR0_L 0xC000
#define TC3XX_CPU_DPR0_U 0xC004
#define TC3XX_CPU_DPR1_L 0xC008
#define TC3XX_CPU_DPR1_U 0xC00C
#define TC3XX_CPU_DPR2_L 0xC010
#define TC3XX_CPU_DPR2_U 0xC014
#define TC3XX_CPU_DPR3_L 0xC018
#define TC3XX_CPU_DPR3_U 0xC01C
#define TC3XX_CPU_DPR4_L 0xC020
#define TC3XX_CPU_DPR4_U 0xC024
#define TC3XX_CPU_DPR5_L 0xC028
#define TC3XX_CPU_DPR5_U 0xC02C
#define TC3XX_CPU_DPR6_L 0xC030
#define TC3XX_CPU_DPR6_U 0xC034
#define TC3XX_CPU_DPR7_L 0xC038
#define TC3XX_CPU_DPR7_U 0xC03C
#define TC3XX_CPU_DPR8_L 0xC040
#define TC3XX_CPU_DPR8_U 0xC044
#define TC3XX_CPU_DPR9_L 0xC048
#define TC3XX_CPU_DPR9_U 0xC04C
#define TC3XX_CPU_DPR10_L 0xC050
#define TC3XX_CPU_DPR10_U 0xC054
#define TC3XX_CPU_DPR11_L 0xC058
#define TC3XX_CPU_DPR11_U 0xC05C
#define TC3XX_CPU_DPR12_L 0xC060
#define TC3XX_CPU_DPR12_U 0xC064
#define TC3XX_CPU_DPR13_L 0xC068
#define TC3XX_CPU_DPR13_U 0xC06C
#define TC3XX_CPU_DPR14_L 0xC070
#define TC3XX_CPU_DPR14_U 0xC074
#define TC3XX_CPU_DPR15_L 0xC078
#define TC3XX_CPU_DPR15_U 0xC07C
#define TC3XX_CPU_DPR16_L 0xC080
#define TC3XX_CPU_DPR16_U 0xC084
#define TC3XX_CPU_DPR17_L 0xC088
#define TC3XX_CPU_DPR17_U 0xC08C
#define TC3XX_CPU_CPR0_L 0xD000
#define TC3XX_CPU_CPR0_U 0xD004
#define TC3XX_CPU_CPR1_L 0xD008
#define TC3XX_CPU_CPR1_U 0xD00C
#define TC3XX_CPU_CPR2_L 0xD010
#define TC3XX_CPU_CPR2_U 0xD014
#define TC3XX_CPU_CPR3_L 0xD018
#define TC3XX_CPU_CPR3_U 0xD01C
#define TC3XX_CPU_CPR4_L 0xD020
#define TC3XX_CPU_CPR4_U 0xD024
#define TC3XX_CPU_CPR5_L 0xD028
#define TC3XX_CPU_CPR5_U 0xD02C
#define TC3XX_CPU_CPR6_L 0xD030
#define TC3XX_CPU_CPR6_U 0xD034
#define TC3XX_CPU_CPR7_L 0xD038
#define TC3XX_CPU_CPR7_U 0xD03C
#define TC3XX_CPU_CPR8_L 0xD040
#define TC3XX_CPU_CPR8_U 0xD044
#define TC3XX_CPU_CPR9_L 0xD048
#define TC3XX_CPU_CPR9_U 0xD04C
#define TC3XX_CPU_CPXE_0 0xE000
#define TC3XX_CPU_CPXE_1 0xE004
#define TC3XX_CPU_CPXE_2 0xE008
#define TC3XX_CPU_CPXE_3 0xE00C
#define TC3XX_CPU_CPXE_4 0xE040
#define TC3XX_CPU_CPXE_5 0xE044
#define TC3XX_CPU_DPRE_0 0xE010
#define TC3XX_CPU_DPRE_1 0xE014
#define TC3XX_CPU_DPRE_2 0xE018
#define TC3XX_CPU_DPRE_3 0xE01C
#define TC3XX_CPU_DPRE_4 0xE050
#define TC3XX_CPU_DPRE_5 0xE054
#define TC3XX_CPU_DPWE_0 0xE020
#define TC3XX_CPU_DPWE_1 0xE024
#define TC3XX_CPU_DPWE_2 0xE028
#define TC3XX_CPU_DPWE_3 0xE02C
#define TC3XX_CPU_DPWE_4 0xE060
#define TC3XX_CPU_DPWE_5 0xE064
#if defined(CONFIG_ARCH_TC3XX)
#  include <arch/tc3xx/irq.h>
#elif defined(CONFIG_ARCH_TC4XX)
#  include <arch/tc4xx/irq.h>
#else
# error "Unsupported tricore arch family"
#endif

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
#if (CONFIG_ARCH_IRQ_NESTING_LIMIT > 1)
#ifdef CONFG_SMP
EXTERN uintptr_t *g_current_regs[CONFIG_SMP_NCPUS][CONFIG_ARCH_IRQ_NESTING_LIMIT];
#else
EXTERN uintptr_t *g_current_regs[CONFIG_ARCH_IRQ_NESTING_LIMIT];
#define g_current_regs this_cpu_var(g_current_regs)
#endif
#endif

#define CURRENT_REGS up_current_regs()

noinstrument_function static inline_function uint32_t tricore_get_a0reg(void)
{
  uint32_t val;
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
   __asm volatile( "mov.d  %0, a0" :"=d"(val)::);
#else
   __asm__ volatile ("mov.d %0, %%a0": "=d" (val) : :"a0");
#endif
  return val;
}

noinstrument_function static inline_function uint32_t tricore_get_a1reg(void)
{
  uint32_t val;
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
   __asm volatile( "mov.d  %0, a1" :"=d"(val)::);
#else
   __asm__ volatile ("mov.d %0, %%a1": "=d" (val) : :"a1");
#endif
  return val;
}

noinstrument_function static inline_function uint32_t tricore_get_a8reg(void)
{
  uint32_t val;
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
   __asm volatile( "mov.d  %0, a8" :"=d"(val)::);
#else
   __asm__ volatile ("mov.d %0, %%a8": "=d" (val) : :"a8");
#endif
  return val;
}

noinstrument_function static inline_function uint32_t tricore_get_a9reg(void)
{
  uint32_t val;
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
   __asm volatile( "mov.d  %0, a9" :"=d"(val)::);
#else
   __asm__ volatile ("mov.d %0, %%a9": "=d" (val) : :"a9");
#endif
  return val;
}

noinstrument_function static inline_function void tricore_set_a0reg(uint32_t val)
{
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
  __asm volatile("mov.a  a0, %0" ::"d"(val):"a0");
#else
  __setareg(a0,val);
#endif
}

noinstrument_function static inline_function void tricore_set_a1reg(uint32_t val)
{
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
  __asm volatile("mov.a  a1, %0" ::"d"(val):"a1");
#else
  __setareg(a1,val);
#endif
}

noinstrument_function static inline_function void tricore_set_a8reg(uint32_t val)
{
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
  __asm volatile("mov.a  a8, %0" ::"d"(val):"a8");
#else
  __setareg(a8,val);
#endif
}

noinstrument_function static inline_function void tricore_set_a9reg(uint32_t val)
{
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
  __asm volatile("mov.a  a9, %0" ::"d"(val):"a9");
#else
  __setareg(a9,val);
#endif
}

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: up_cpu_index
 *
 * Description:
 *   Return the real core number regardless CONFIG_SMP setting
 *
 ****************************************************************************/
static inline int up_cpu_index(void)
{
#ifdef CONFIG_ARCH_HAVE_MULTICPU
  return __mfcr(TC3XX_CPU_CORE_ID) & 0x7u;
#else
  return 0;
#endif
}

/****************************************************************************
 * Name: up_irq_enable
 *
 * Description:
 *   Enable interrupts globally.
 *
 ****************************************************************************/

void up_irq_enable(void);

/****************************************************************************
 * Inline functions
 ****************************************************************************/

noinstrument_function static inline uintptr_t up_getsp(void)
{
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
  return (uintptr_t)__get_sp();
#else
  return __builtin_frame_address(0);
#endif
}

/****************************************************************************
 * Name: up_irq_disable
 *
 * Description:
 *   Disable interrupts
 *
 ****************************************************************************/
noinstrument_function static inline void up_irq_disable(void)
{
  __disable();
}

/****************************************************************************
 * Name: up_irq_save
 *
 * Description:
 *   Disable interrupts and return the previous value of the mstatus register
 *
 ****************************************************************************/

noinstrument_function static inline irqstate_t up_irq_save(void)
{
  return __disable_and_save();
}

/****************************************************************************
 * Name: up_irq_restore
 *
 * Description:
 *   Restore the value of the mstatus register
 *
 ****************************************************************************/

noinstrument_function static inline void up_irq_restore(irqstate_t flags)
{
  __restore(flags);
}

static inline_function uint8_t up_get_irq_nesting(void)
{
  return (uint8_t)tricore_get_a0reg();
}

static inline_function uint8_t up_increase_irq_nesting(void)
{
  uint32_t irq_nesting = tricore_get_a0reg();
  irq_nesting++;
  tricore_set_a0reg(irq_nesting);
  return (uint8_t)irq_nesting;
}

static inline_function uint8_t up_decrease_irq_nesting(void)
{
  uint32_t irq_nesting = tricore_get_a0reg();
  irq_nesting--;
  tricore_set_a0reg(irq_nesting);
  return (uint8_t)irq_nesting;
}

#ifdef CONFIG_RT_FRAMEWORK

static inline_function
uint32_t up_clz(uint32_t val)
{
   uint32_t count;

#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
   __asm volatile("clz %0,%1":"=d"(count):"d"(val));
#else
   __asm__ volatile("clz %0,%1":"=d"(count):"d"(val));
#endif

  return count;
}

static inline_function irqlevel_t up_get_irq_mask_level(void)
{
  return (__mfcr(TRICORE_CPU_ICR) & ICR_CCPN_MASK);
}

static inline_function void up_set_irq_mask_level(irqlevel_t level)
{
  __mtcr( TRICORE_CPU_ICR, ((__mfcr( TRICORE_CPU_ICR ) & (~ICR_CCPN_MASK)) | level) );
  __isync();
}

static inline_function irqlevel_t up_get_irq_running_level(void)
{
  return up_get_irq_mask_level();
}

static inline_function irqlevel_t up_irq_level_save(irqlevel_t level)
{
  uintptr_t icr = (uintptr_t)__mfcr(TRICORE_CPU_ICR);
  irqlevel_t pre_level = (icr & ICR_CCPN_MASK) >> ICR_CCPN;

  if (level > pre_level) {
    icr &= ~ICR_CCPN_MASK;
    icr |= (level << ICR_CCPN);
    __mtcr(TRICORE_CPU_ICR, icr);
    __isync();
  }
  return pre_level;
}

static inline_function void up_irq_level_restore(irqlevel_t level)
{
  up_set_irq_mask_level(level);
}

static inline_function irqlevel_t up_kernel_int_save(void)
{
#ifdef CONFIG_RT_FRAMEWORK_INT_LEVEL
  return up_irq_level_save(CONFIG_RT_FRAMEWORK_MAX_TP_INT_LEVEL);
#else
  return up_irq_save();
#endif
}

static inline_function void up_kernel_int_restore(irqlevel_t level)
{
#ifdef CONFIG_RT_FRAMEWORK_INT_LEVEL
  up_irq_level_restore(level);
#else
  up_irq_restore(level);
#endif
}

noinstrument_function static inline void up_set_contexthdl(void * const ctxhdl)
{
  tricore_set_a8reg((uint32_t)ctxhdl);
}

noinstrument_function static inline void * up_get_contexthdl(void)
{
  return (void *)tricore_get_a8reg();
}

#ifdef CONFIG_RT_FRAMEWORK_SYSCALL
static inline_function void up_syscall(void *syscall_args)
{
  sys_call2(SYS_syscall_return, (uintptr_t)syscall_args, (uintptr_t)0);
}
#endif

#ifdef CONFIG_RT_FRAMEWORK_HOOK
static inline_function void up_switch_hook_context(uint32_t param0, void *param1, void *param2)
{
  sys_call3(SYS_switch_hook_context, (uintptr_t)param0, (uintptr_t)param1, (uintptr_t)param2);
}
#endif

#ifdef CONFIG_RT_FRAMEWORK_ISOLATE
static inline_function void up_ppc_switch(const uint32_t ppc_flag, const uint32_t func_id, void *ppc_ctx_args)
{
  sys_call3(SYS_ppc_switch, ppc_flag, func_id, (uintptr_t)ppc_ctx_args);
}
#endif

static inline_function void tricore_set_isp(void)
{
	if (up_get_irq_nesting() == 0) {
		uintptr_t isp = __mfcr(TRICORE_CPU_ISP);
#ifdef CONFIG_TRICORE_TOOLCHAIN_TASKING
		__asm volatile("mov.a  a10, %0" ::"d"(isp) : "a10");
#else
		__setareg(a10, isp);
#endif
	}
}

#endif

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

static inline_function uintptr_t *up_current_regs(void)
{
#if (CONFIG_ARCH_IRQ_NESTING_LIMIT >1)
  uint32_t index = up_get_irq_nesting();
#ifdef CONFG_SMP
  return (uintptr_t *)g_current_regs[up_cpu_index()][--index];
#else
  return (uintptr_t *)g_current_regs[--index];
#endif
#else
  return (uintptr_t *)tricore_get_a9reg();
#endif

}

static inline_function void up_set_current_regs(uintptr_t *regs)
{
#if (CONFIG_ARCH_IRQ_NESTING_LIMIT >1)
  uint32_t index = up_get_irq_nesting();

#ifdef CONFG_SMP
  g_current_regs[up_cpu_index()][--index] = regs;
#else
  g_current_regs[--index] = regs;
#endif
#else
  tricore_set_a9reg((uintptr_t)regs);
#endif
}

/****************************************************************************
 * Name: up_getusrpc
 ****************************************************************************/
#define __tricore_csa2addr(csa) ((uintptr_t *)((((csa) & 0x000F0000) << 12) \
                                             | (((csa) & 0x0000FFFF) << 6)))
static inline uintptr_t * up_getusrpc(void *regs)
{
  uintptr_t *plcsa = (uintptr_t *)((regs) ? (regs) : up_current_regs());

  __dsync();

  uintptr_t *pucsa = (uintptr_t *)__tricore_csa2addr(plcsa[REG_UPCXI]);
  return (uintptr_t *)pucsa[REG_UPC];
}


/****************************************************************************
 * Name: up_interrupt_context
 *
 * Description:
 *   Return true is we are currently executing in the interrupt
 *   handler context.
 *
 ****************************************************************************/

noinstrument_function
static inline_function bool up_interrupt_context(void)
{
  return up_get_irq_nesting() != 0;
}
#endif /* __ASSEMBLY__ */

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ARCH_TRICORE_INCLUDE_IRQ_H */
