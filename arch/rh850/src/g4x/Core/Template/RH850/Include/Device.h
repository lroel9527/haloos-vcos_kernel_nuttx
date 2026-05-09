/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

//! [RH850-Device-IO-Header-File]

/*******************************************************************************************************************//**
 * @file     <Device>.h
 * @brief    RH850 Device Header File for Device <Device>
 * @version  V0.0.1
 * @date     01. Jan 2026
 **********************************************************************************************************************/

/** @addtogroup Renesas Electronics Corporation
 * @{
 */

/** @addtogroup device
 * @{
 */

#ifndef DEVICE_H
 #define DEVICE_H

 #ifdef __cplusplus
extern "C" {
 #endif

/** @addtogroup Configuration_of_RH850
 * @{
 */

/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */
/* ============================  Configuration of the RH850 G4MH Processor and Core Peripherals  ============================= */
 #if (__RH850_G4MH__)
  #define __RH850_G4MH_REV    0x0001U  /*!< RH850 G4MH Core Revision                                         */
  #define __FPU_PRESENT       1        /*!< FPU present                                                      */
  #if ((defined(RH850U2BX_BUILD) && (RH850U2BX_BUILD == 1)) || (defined(RH850U2BXE_BUILD) && (RH850U2BXE_BUILD == 1)))
   #define __FXU_PRESENT      1        /*!< FXU present                                                      */
  #endif /* #if ((defined(RH850U2BX_BUILD) && (RH850U2BX_BUILD == 1)) || (defined(RH850U2BXE_BUILD) && (RH850U2BXE_BUILD == 1))) */
  #define __ICACHE_PRESENT    1        /*!< ICACHE prsent                                                    */
  #define __IRQ_PRESENT       1        /*!< IRQ prsent                                                       */
  #define __MPU_PRESENT       1        /*!< MPU prsent                                                       */
  #define __PMU_PRESENT       1        /*!< PMU prsent                                                       */
  #define __TSC_PRESENT       1        /*!< TSC prsent                                                       */
  #include "core_g4mh.h"
 #elif (__RH850_G4KH__)
  #define __RH850_G4KH_REV    0x0001U  /*!< RH850 G4MH Core Revision                                         */
  #define __FPU_PRESENT       1        /*!< FPU present                                                      */
  #define __ICACHE_PRESENT    1        /*!< ICACHE prsent                                                    */
  #define __IRQ_PRESENT       1        /*!< IRQ prsent                                                       */
  #define __MPU_PRESENT       1        /*!< MPU prsent                                                       */
  #define __PMU_PRESENT       1        /*!< PMU prsent                                                       */
  #define __TSC_PRESENT       1        /*!< TSC prsent                                                       */

  #include "core_g4kh.h"
 #endif

/** @} */ /* End of group Configuration_of_RH850 */

 #include "system_Device.h"            /*!< System                                                                */

/* ========================================  Start of section using anonymous unions  ======================================== */

/* ToDo: add here your device specific peripheral access structure typedefs
 *       including bit definitions for Pos/Msk macros
 *       following is an example for a timer */

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_EINT                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief This section describes the interrupt units. (R_EINT)
 */

typedef struct                         /*!< (@ 0xFFC00000) R_EINT Structure                                           */
{
    union
    {
        __IOM uint8_t SINTC0;          /*!< (@ 0x00000000) SINTR0 to SINTR3 are 8-bit registers used to
                                        *                  control software interrupts 0 to 3 (SINT0
                                        *                  to SINT3).Writing 01H to these registers
                                        *                  increments the value of the counter; writing
                                        *                  00H decrements it. When thevalue of the
                                        *                  counter for any of these registers is 1
                                        *                  or more, the corresponding interrupt from
                                        *                  amongsoftware interrupts 0 to 3 (SINT0 to
                                        *                  SINT3) is generated. When reading the value
                                        *                  from any of theseregisters, the read value
                                        *                  is the current value of the counter.                       */

        struct
        {
            __IOM uint8_t SINTC : 8;   /*!< [7..0] Software Interrupt RequestThis bit generates a software
                                        *   interrupt.[Reading operation]The number of SINTn interrupt
                                        *   request counts is read out.[Writing operation]Writing 01H:
                                        *   Increments the counter.*1Writing 00H: Decrements the counter.*2           */
        } SINTC0_b;
    };
    __IM uint8_t RESERVED[3];

    union
    {
        __IOM uint8_t SINTC1;          /*!< (@ 0x00000004) SINTR0 to SINTR3 are 8-bit registers used to
                                        *                  control software interrupts 0 to 3 (SINT0
                                        *                  to SINT3).Writing 01H to these registers
                                        *                  increments the value of the counter; writing
                                        *                  00H decrements it. When thevalue of the
                                        *                  counter for any of these registers is 1
                                        *                  or more, the corresponding interrupt from
                                        *                  amongsoftware interrupts 0 to 3 (SINT0 to
                                        *                  SINT3) is generated. When reading the value
                                        *                  from any of theseregisters, the read value
                                        *                  is the current value of the counter.                       */

        struct
        {
            __IOM uint8_t SINTC : 8;   /*!< [7..0] Software Interrupt RequestThis bit generates a software
                                        *   interrupt.[Reading operation]The number of SINTn interrupt
                                        *   request counts is read out.[Writing operation]Writing 01H:
                                        *   Increments the counter.*1Writing 00H: Decrements the counter.*2           */
        } SINTC1_b;
    };
    __IM uint8_t RESERVED1[3];

    union
    {
        __IOM uint8_t SINTC2;          /*!< (@ 0x00000008) SINTR0 to SINTR3 are 8-bit registers used to
                                        *                  control software interrupts 0 to 3 (SINT0
                                        *                  to SINT3).Writing 01H to these registers
                                        *                  increments the value of the counter; writing
                                        *                  00H decrements it. When thevalue of the
                                        *                  counter for any of these registers is 1
                                        *                  or more, the corresponding interrupt from
                                        *                  amongsoftware interrupts 0 to 3 (SINT0 to
                                        *                  SINT3) is generated. When reading the value
                                        *                  from any of theseregisters, the read value
                                        *                  is the current value of the counter.                       */

        struct
        {
            __IOM uint8_t SINTC : 8;   /*!< [7..0] Software Interrupt RequestThis bit generates a software
                                        *   interrupt.[Reading operation]The number of SINTn interrupt
                                        *   request counts is read out.[Writing operation]Writing 01H:
                                        *   Increments the counter.*1Writing 00H: Decrements the counter.*2           */
        } SINTC2_b;
    };
    __IM uint8_t RESERVED2[3];

    union
    {
        __IOM uint8_t SINTC3;          /*!< (@ 0x0000000C) SINTR0 to SINTR3 are 8-bit registers used to
                                        *                  control software interrupts 0 to 3 (SINT0
                                        *                  to SINT3).Writing 01H to these registers
                                        *                  increments the value of the counter; writing
                                        *                  00H decrements it. When thevalue of the
                                        *                  counter for any of these registers is 1
                                        *                  or more, the corresponding interrupt from
                                        *                  amongsoftware interrupts 0 to 3 (SINT0 to
                                        *                  SINT3) is generated. When reading the value
                                        *                  from any of theseregisters, the read value
                                        *                  is the current value of the counter.                       */

        struct
        {
            __IOM uint8_t SINTC : 8;   /*!< [7..0] Software Interrupt RequestThis bit generates a software
                                        *   interrupt.[Reading operation]The number of SINTn interrupt
                                        *   request counts is read out.[Writing operation]Writing 01H:
                                        *   Increments the counter.*1Writing 00H: Decrements the counter.*2           */
        } SINTC3_b;
    };
} R_EINT_Type;                         /*!< Size = 13 (0xd)                                                           */

/** @} */ /* End of group Device_Peripheral_peripherals */

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripheralAddr
 * @{
 */

 #define R_EINT_BASE    0xFFC00000UL

/** @} */ /* End of group Device_Peripheral_peripheralAddr */

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_declaration
 * @{
 */

 #define R_EINT    ((R_EINT_Type *) R_EINT_BASE)

/** @} */ /* End of group Device_Peripheral_declaration */

/* =========================================  End of section using anonymous unions  ========================================= */

/* =========================================================================================================================== */
/* ================                                 Pos/Mask Cluster Section                                  ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_clusters
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_EINT                                           ================ */
/* =========================================================================================================================== */

/* ========================================================  SINTC0  ========================================================= */
 #define R_EINT_SINTC0_SINTC_Pos    (0UL)    /*!< SINTC (Bit 0)                                         */
 #define R_EINT_SINTC0_SINTC_Msk    (0xffUL) /*!< SINTC (Bitfield-Mask: 0xff)                           */
/* ========================================================  SINTC1  ========================================================= */
 #define R_EINT_SINTC1_SINTC_Pos    (0UL)    /*!< SINTC (Bit 0)                                         */
 #define R_EINT_SINTC1_SINTC_Msk    (0xffUL) /*!< SINTC (Bitfield-Mask: 0xff)                           */
/* ========================================================  SINTC2  ========================================================= */
 #define R_EINT_SINTC2_SINTC_Pos    (0UL)    /*!< SINTC (Bit 0)                                         */
 #define R_EINT_SINTC2_SINTC_Msk    (0xffUL) /*!< SINTC (Bitfield-Mask: 0xff)                           */
/* ========================================================  SINTC3  ========================================================= */
 #define R_EINT_SINTC3_SINTC_Pos    (0UL)    /*!< SINTC (Bit 0)                                         */
 #define R_EINT_SINTC3_SINTC_Msk    (0xffUL) /*!< SINTC (Bitfield-Mask: 0xff)                           */

/** @} */ /* End of group PosMask_peripherals */

 #ifdef __cplusplus
}
 #endif

#endif                                 /* DEVICE_H */

/** @} */ /* End of group device */

/** @} */ /* End of group Renesas */

//! [RH850-Device-IO-Header-File]
