/*  */

#ifndef __ARCH_ARM_SRC_U2BX_U2BX_SERIAL_H
#define __ARCH_ARM_SRC_U2BX_U2BX_SERIAL_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Registers offset */
#define U2BX_LIN3_UART_LWBR_OFFSET		0x01	/* Baud Rate Select Register */
#  define U2BX_LIN3_UART_LWBR_NSPB_POS	4
#  define U2BX_LIN3_UART_LWBR_LPRS_POS	1

#define U2BX_LIN3_UART_LBRP_OFFSET		0x02	/* Baud Rate Prescaler Register */

#define U2BX_LIN3_UART_LMD_OFFSET		0x08	/* Mode Register */
#  define U2BX_LIN3_UART_LMD_LRDNFS_POS	5		/* Noise filter bit */

#define U2BX_LIN3_UART_LBFC_OFFSET		0x09	/* Configuration Register */
#  define U2BX_LIN3_UART_LBFC_UTPS_POS	6		/* Output Polarity bit */
#  define U2BX_LIN3_UART_LBFC_URPS_POS	5		/* Input Polarity bit */
#  define U2BX_LIN3_UART_LBFC_UPS_POS	3		/* Parity bits */
#  define U2BX_LIN3_UART_LBFC_USBLS_POS	2		/* Stop Bit Length bit */
#  define U2BX_LIN3_UART_LBFC_UBOS_POS	1		/* Transfer Format Order bit */
#  define U2BX_LIN3_UART_LBFC_UBLS_POS	0		/* Character Length bit */

#define U2BX_LIN3_UART_LSC_OFFSET		0x0A	/* Space Configuration Register */

#define U2BX_LIN3_UART_LEDE_OFFSET		0x0D	/* Error Detection Enable Register */
#  define U2BX_LIN3_UART_LEDE_FERE_POS	3		/* Framing Error Detection Enable bit */
#  define U2BX_LIN3_UART_LEDE_OERE_POS	2		/* Overrun Error Detection Enable bit */
#  define U2BX_LIN3_UART_LEDE_BERE_POS	0		/* Bit Error Detection Enable bit */

#define U2BX_LIN3_UART_LCUC_OFFSET		0x0E	/* Control Register */
#define U2BX_LIN3_UART_LTRC_OFFSET		0x10	/* Transmission Control Register */
#  define U2BX_LIN3_UART_LTRC_RTS_POS	1		/* Transmission Start bit */

#define U2BX_LIN3_UART_LMST_OFFSET		0x11	/* Mode Status Register */
#define U2BX_LIN3_UART_LST_OFFSET		0x12	/* Status Register */
#define R_RLN30_LST_UTS_Msk               (0x10UL)
#define R_RLN30_LST_FTC_Msk               (0x1UL)
#define R_RLN30_LST_URS_Msk               (0x20UL)
#  define U2BX_LIN3_UART_LST_URS_POS	5		/* Reception Status Flag bit */
#  define U2BX_LIN3_UART_LST_UTS_POS	4		/* Transmission Status Flag bit */
#  define U2BX_LIN3_UART_LST_ERR_POS	3		/* Error Detection Flag bit */
#  define U2BX_LIN3_UART_LST_FTC_POS	0		/* Successful Buffer Transmission Flag bit */
#define U2BX_LIN3_UART_LEST_OFFSET		0x13	/* Error Status Register */

#define U2BX_LIN3_UART_LDFC_OFFSET		0x14	/* Data Field Configuration Register */
#  define U2BX_LIN3_UART_LDFC_UTSW_POS	5		/* Transmission Start Wait bit */
#  define U2BX_LIN3_UART_LDFC_MDL_POS	0		/* Buffer Data Length Select bit */

#define U2BX_LIN3_UART_LIDB_OFFSET		0x15	/* ID Buffer Register */
#define U2BX_LIN3_UART_LUDB0_OFFSET		0x17	/* Data Buffer 0 Register */
#define U2BX_LIN3_UART_LDBR1_OFFSET		0x18	/* Data Buffer 1 Register */
#define U2BX_LIN3_UART_LDBR2_OFFSET		0x19	/* Data Buffer 2 Register */
#define U2BX_LIN3_UART_LDBR3_OFFSET		0x1A	/* Data Buffer 3 Register */
#define U2BX_LIN3_UART_LDBR4_OFFSET		0x1B	/* Data Buffer 4 Register */
#define U2BX_LIN3_UART_LDBR5_OFFSET		0x1C	/* Data Buffer 5 Register */
#define U2BX_LIN3_UART_LDBR6_OFFSET		0x1D	/* Data Buffer 6 Register */
#define U2BX_LIN3_UART_LDBR7_OFFSET		0x1E	/* Data Buffer 7 Register */
#define U2BX_LIN3_UART_LDBR8_OFFSET		0x1F	/* Data Buffer 8 Register */

#define U2BX_LIN3_UART_LUOER_OFFSET		0x20	/* Operation Enable Register */
#  define U2BX_LIN3_UART_LUOER_UROE_POS	1		/* Reception Enable bit */
#  define U2BX_LIN3_UART_LUOER_UTOE_POS	0		/* Transmission Enable bit */

#define U2BX_LIN3_UART_LUOR1_OFFSET		0x21	/* Option Register 1 */
#  define U2BX_LIN3_UART_LUOR1_UTIGTS_POS 3		/* TXI Timing bit */

#define U2BX_LIN3_UART_LUTDR_OFFSET		0x24	/* Transmission Data Register */
#define U2BX_LIN3_UART_LURDR_OFFSET		0x26	/* Reception Data Register */
#define U2BX_LIN3_UART_LUWTDR_OFFSET	0x28	/* Wait Transmission Data Register */

/* Register Preset Value */
/* Uart control */
#define U2BX_LCUC_LIN_RESET				0x00
#define U2BX_LCUC_LIN_RESET_CANCELED	0x01

/* Parity */
#define U2BX_PARITY_DISABLE	0x0
#define U2BX_PARITY_EVEN	0x1
#define U2BX_PARITY_ODD		0x3

/* Expansion bit */
#define U2BX_LUOR1_EXPANSION_DISABLE	0x00

/* Uart Mode */
#define U2BX_LMD_UART_MODE 0x01

/* Default data transmission configuration */
#define U2BX_LDFC_1BYTE_NO_WAIT				\
	(0 << U2BX_LIN3_UART_LDFC_UTSW_POS |	\
	 1 << U2BX_LIN3_UART_LDFC_MDL_POS)

/* Enable TX-RX */
#define U2BX_UART_ENABLE_TX (1 << U2BX_LIN3_UART_LUOER_UTOE_POS)
#define U2BX_UART_ENABLE_RX (1 << U2BX_LIN3_UART_LUOER_UROE_POS)
#define U2BX_UART_ENABLE_TX_RX (U2BX_UART_ENABLE_TX | U2BX_UART_ENABLE_RX)

/* Start transmission */
#define U2BX_UART_TX_START	(1 << U2BX_LIN3_UART_LTRC_RTS_POS)

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions Prototypes
 ****************************************************************************/

#endif