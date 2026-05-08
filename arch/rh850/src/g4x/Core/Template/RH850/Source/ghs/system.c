/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

#if CONFIG_BSP_FSP_SUPPORT
#include "bsp_api.h"
#else
#include "Device_common.h"
#endif
#include <nuttx/config.h>


/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/* Heap boundaries provided by the linker script */
extern uint32_t __ghsbegin_heap;
extern uint32_t __ghsend_heap;
extern uint32_t __ghsbegin_kheap;
extern uint32_t __ghsend_kheap;
extern uint32_t * uxInterruptStack;

/* Variables that store heap start/end addresses as uint32_t values */
uint32_t __heap_start = (uint32_t) &__ghsbegin_heap;
uint32_t __heap_end   = (uint32_t) &__ghsend_heap;
/* Variables that store heap start/end addresses as uint32_t values */
uint32_t __kheap_start = (uint32_t) &__ghsbegin_kheap;
uint32_t __kheap_end   = (uint32_t) &__ghsend_kheap;


/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* Address Access Mutual Exclusion Mechanism */
#if (BSP_CFG_MEV_SIZE_BYTES > 0)
 #pragma ghs section sbss=".mev_address"

/* Used in baremetal pack */
uint32_t g_mev_cpusync_address;

/* Used in baremetal pack */
uint32_t g_mev_address[BSP_CFG_MEV_SIZE_BYTES >> 2];
#else
 #pragma ghs section sbss=".mev_address"

/* Used in baremetal pack */
uint32_t g_mev_cpusync_address;
#endif

#define BSP_INTERRUPT_STACK_SIZE    0x9000
#define BSP_MAIN_STACK_SIZE         0x5000
#define BSP_HEAP_SIZE               0x10000
#define BSP_KHEAP_SIZE              0x10000

/* Main stack definition section */
#pragma ghs section bss=".stack_pe0"
uint32_t g_interrupt_stack_pe0[BSP_INTERRUPT_STACK_SIZE >> 2];
uint32_t g_main_stack_pe0[BSP_MAIN_STACK_SIZE >> 2];

#if (BSP_PE1_USED)
 #pragma ghs section sbss=".stack_pe1"
uint32_t g_main_stack_pe1[BSP_CFG_STACK_MAIN_BYTES >> 2];
#endif

/* Heap definition section (only if heap size is greater than 0) */

#pragma ghs section bss=".heap"
uint32_t _REL_sysheap[BSP_HEAP_SIZE >> 2];
uint32_t _REL_sizeof_sysheap = BSP_HEAP_SIZE >> 2;
#pragma ghs section bss=".kheap"
uint32_t _REL_k_sysheap[BSP_KHEAP_SIZE >> 2];
uint32_t _REL_sizeof_syskheap = BSP_KHEAP_SIZE >> 2;

#pragma ghs section sbss = default
uint32_t *  uxInterruptStack  = (uint32_t *)&g_interrupt_stack_pe0[BSP_INTERRUPT_STACK_SIZE>>2];

uint32_t checkcrash_cstart = 0;
#if (CONFIG_BSP_FSP_SUPPORT == 1)
extern void R_BSP_WarmStart(void);
#endif
extern void R_BSP_FPU_Init();
void SystemInit(void);


/*******************************************************************************************************************//**
 * Initialize the MCU and the runtime environment.
 **********************************************************************************************************************/

 void SystemInit (void)
{
    /* Get the current core ID */

    /* Call Post C runtime initialization hook for RESET stage */

    /* Check if the System Init is invoked in CPU0 */
    {
        /* Configure system clocks and Guard */
        
#if (CONFIG_BSP_FSP_SUPPORT == 1)
        R_BSP_WarmStart();
#endif
        /* Call Post C runtime initialization hook for POST CLOCK stage */
    }

    /* Call Post C runtime initialization hook. */


    /* Configure MPU */

    /* Instruction cache is enabled by default; disable it by changing Instruction Cache Enable option in BSP tab */

    /* FPU Init */
    R_BSP_FPU_Init();
}
