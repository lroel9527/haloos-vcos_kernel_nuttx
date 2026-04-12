/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     Device_common.h
 * @brief    Provides common definitions and declarations for the RH850 G4 environment.
 * @version  V0.0.1
 * @date     01. Jan 2026
 **********************************************************************************************************************/

#ifndef DEVICE_COMMON
 #define DEVICE_COMMON

 #ifdef __cplusplus
extern "C" {
 #endif

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "Device.h"
 #include "memory_regions.h"

// #define BSP_CFG_STACK_MAIN_BYTES 0x1000
// #define BSP_INTC_INTBP_MAX_ENTRIES 1024
// #define BSP_CFG_HEAP_SIZE_BYTES    1024

#define __GHS__  1

/* This is the value used to mark the stack for subsequent stack monitoring
 * logic.
 */

#define STACK_COLOR    0xdeadbeef
#define INTSTACK_COLOR 0xdeadbeef
#define HEAP_COLOR     'h'

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #if defined(__CCRH__)

/* Create the pragma inline statement with the function name as argument */
  #define BSP_PRAGMA_SECTION_DEFAULT        default
  #define BSP_PRAGMA_SECTION_INTVECT_PE0    .inttable_PE0
  #define BSP_PRAGMA_SECTION_INTVECT_PE1    .inttable_PE1

  #define BSP_PRAGMA_SECTION_DATA
  #define BSP_PRAGMA_SECTION_ROM_DATA
  #define BSP_PRAGMA_SECTION_BSS
  #define BSP_PRAGMA_SECTION_TEXT

  #define BSP_INTERRUPT_ATTRIBUTE      ///< Interrupt attribute placeholder for CCRH

 #elif defined(__ghs__)

/* Create the pragma inline statement with the function name as argument */
  #define BSP_PRAGMA_SECTION_DEFAULT        default
  #define BSP_PRAGMA_SECTION_INTVECT_PE0    ".inttable_PE0"
  #define BSP_PRAGMA_SECTION_INTVECT_PE1    ".inttable_PE1"

  #define BSP_PRAGMA_SECTION_DATA           sdata
  #define BSP_PRAGMA_SECTION_ROM_DATA       rosdata
  #define BSP_PRAGMA_SECTION_BSS            sbss
  #define BSP_PRAGMA_SECTION_TEXT           text

  #define BSP_INTERRUPT_ATTRIBUTE           __interrupt ///< Interrupt attribute for GHS compiler

 #elif defined(__ICCRH850__)
  #define BSP_PRAGMA_SECTION_DEFAULT        "default"
  #define BSP_PRAGMA_SECTION_INTVECT_PE0    ".inttable_PE0.data"
  #define BSP_PRAGMA_SECTION_INTVECT_PE1    ".inttable_PE1.data"

  #define BSP_PRAGMA_SECTION_DATA           default_variable_attributes
  #define BSP_PRAGMA_SECTION_ROM_DATA       default_variable_attributes
  #define BSP_PRAGMA_SECTION_BSS            default_variable_attributes
  #define BSP_PRAGMA_SECTION_TEXT           default_function_attributes

  #define BSP_INTERRUPT_ATTRIBUTE           __ei_int __interrupt ///< Interrupt attribute placeholder for IAR

 #endif

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

 #ifdef __cplusplus
}
 #endif

#endif
