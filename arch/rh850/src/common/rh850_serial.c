/*
 * Copyright (c) 2025 Li Auto Inc. and its affiliates
 * Licensed under the Apache License, Version 2.0(the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <nuttx/config.h>

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/serial/serial.h>

#include <arch/board/board.h>

#include "rh850_internal.h"
#include "rh850_serial.h"

#include "r_rlin3_uart.h"
#include "r_uart_api.h"

#undef uint32
#define uint32 uint32_t

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Which UART with be tty0/console and which tty1?  The console will always
 * be ttyS0.  If there is no console then will use the lowest numbered UART.
 */

#define CONSOLE_DEV g_uart0port /* UART0 is console */
#define TTYS0_DEV g_uart0port	/* UART0 is ttyS0 */

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct up_dev_s
{
	uint32_t uartbase; /* Base address of UART registers */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static int up_setup(struct uart_dev_s *dev);
static void up_shutdown(struct uart_dev_s *dev);
static int up_attach(struct uart_dev_s *dev);
static void up_detach(struct uart_dev_s *dev);
static int up_ioctl(struct file *filep, int cmd, unsigned long arg);
static int up_receive(struct uart_dev_s *dev, unsigned int *status);
static void up_rxint(struct uart_dev_s *dev, bool enable);
static bool up_rxavailable(struct uart_dev_s *dev);
static void up_send(struct uart_dev_s *dev, int ch);
static void up_txint(struct uart_dev_s *dev, bool enable);
static bool up_txready(struct uart_dev_s *dev);

#if defined(CONFIG_RT_FRAMEWORK) && (CONFIG_RT_FRAMEWORK == 1)
void up_uart_rx_handler(void);
#else
static int up_txiinterrupt(int irq, void *context, void *arg);
static int up_rxiinterrupt(int irq, void *context, void *arg);
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct uart_ops_s g_uart_ops =
	{
		.setup = up_setup,
		.shutdown = up_shutdown,
		.attach = up_attach,
		.detach = up_detach,
		.ioctl = up_ioctl,
		.receive = up_receive,
		.rxint = up_rxint,
		.rxavailable = up_rxavailable,
#ifdef CONFIG_SERIAL_IFLOWCONTROL
		.rxflowcontrol = NULL,
#endif
		.send = up_send,
		.txint = up_txint,
		.txready = up_txready,
		.txempty = up_txready,
		.recvbuf = NULL,
		.sendbuf = NULL,
};

/* I/O buffers */
#ifdef CONFIG_U2BX_UART0
static char g_uart0rxbuffer[CONFIG_UART0_RXBUFSIZE];
static char g_uart0txbuffer[CONFIG_UART0_TXBUFSIZE];

static struct up_dev_s g_uart0priv =
	{
		//.uartbase = 0xFFC7C000, // LIN3/UART 0 base
		.uartbase = 0xFF89B100, // LIN3/UART1 base
};

static __percpu_data uart_dev_t g_uart0port =
	{
		.recv =
			{
				.size = CONFIG_UART0_RXBUFSIZE,
				.buffer = &g_uart0rxbuffer[0],
			},
		.xmit =
			{
				.size = CONFIG_UART0_TXBUFSIZE,
				.buffer = &g_uart0txbuffer[0],
			},
		.ops = &g_uart_ops,
		.priv = &g_uart0priv,
};
#define g_uart0port this_cpu_var(g_uart0port)
#endif

static void r_rlin3_uart_callback(uart_callback_args_t *p_args)
{
	(void)p_args;
}

baud_setting_t g_uart0_baud_setting =
	{
		/* Baud rate calculated with 0.208% error. */
		.bit_sampling = 10,
		.prescaler_clock = 0,
		.prescaler = 62};

/** UART extended configuration for UARTonRLIN3 HAL driver */
const rlin3_uart_extended_cfg_t g_uart0_cfg_extend =
	{.operation_enable = UART_DIR_RX_TX,
	 .enb_bit_err = 0,
	 .enb_overrun_err = 0,
	 .enb_frame_err = 0,
	 .inter_byte_space = 0,
	 .noise_cancel = RLIN3_UART_NOISE_CANCELLATION_DISABLE,
	 .p_baud_setting = &g_uart0_baud_setting,
	 .expansion_bit_enable = RLIN3_UART_EXPANSION_BIT_DISABLE,
	 .expansion_bit_comparison = RLIN3_UART_EXPANSION_BIT_COMPARISON_DISABLE,
	 .timing_select = UART_COMPLETION,
	 .transfer_order = UART_LSB_FISRT,
	 .invert_input = UART_NORMAL_INPUT,
	 .invert_output = UART_NORMAL_OUTPUT,
	 .tx_buffer = 0,
#if (BSP_FEATURE_DEVICE_HAS_INTSEL_IRQ)
	 .intsel_irq_cfg = BSP_INTSEL_DISABLED
#endif
};

/** UART interface configuration */
uart_cfg_t g_uart0_cfg =
	{
		.channel = 1,
		.parity = UART_PARITY_OFF,
		.stop_bits = UART_STOP_BITS_1,
		.data_bits = UART_DATA_BITS_8,
		.p_callback = r_rlin3_uart_callback,
		.p_context = NULL,
		.p_extend = &g_uart0_cfg_extend,
		.p_transfer_tx = NULL,
		.p_transfer_rx = NULL,
		.rxi_ipl = (12),
		.txi_ipl = (12),
		.eri_ipl = (12),
		//.rxi_irq = VECTOR_NUMBER_INTRLIN30UR1,     //LIN3/UART0
		//.txi_irq = VECTOR_NUMBER_INTRLIN30UR0,
		//.eri_irq = VECTOR_NUMBER_INTRLIN30UR2};
		.rxi_irq = VECTOR_NUMBER_INTRLIN31UR1,      //LIN3/UART1
		.txi_irq = VECTOR_NUMBER_INTRLIN31UR0,      //LIN3/UART1
		.eri_irq = VECTOR_NUMBER_INTRLIN31UR2};     //LIN3/UART1

rlin3_uart_instance_ctrl_t g_uart0_ctrl;

/****************************************************************************
 * Name: up_setup
 *
 * Description:
 *   Configure the UART baud, bits, parity, etc. This method is called the
 *   first time that the serial port is opened.
 *
 ****************************************************************************/

static int up_setup(struct uart_dev_s *dev)
{
	struct up_dev_s *priv = (struct up_dev_s *)dev->priv;

	fsp_err_t err;

	if (g_uart0_ctrl.open)
	{
		return OK;
		// R_RLIN3_UART_Close(&g_uart0_ctrl);
	}

	err = R_RLIN3_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);

	return (err == FSP_SUCCESS) ? OK : -1;
}

/****************************************************************************
 * Name: up_shutdown
 *
 * Description:
 *   Disable the UART.  This method is called when the serial
 *   port is closed
 *
 ****************************************************************************/

static void up_shutdown(struct uart_dev_s *dev)
{
	(void)dev;

	R_RLIN3_UART_Close(&g_uart0_ctrl);
}

/****************************************************************************
 * Name: up_attach
 *
 * Description:
 *   Configure the UART to operation in interrupt driven mode. This method is
 *   called when the serial port is opened.  Normally, this is just after the
 *   the setup() method is called, however, the serial console may operate in
 *   a non-interrupt driven mode during the boot phase.
 *
 *   RX and TX interrupts are not enabled by the attach method (unless the
 *   hardware supports multiple levels of interrupt enabling).  The RX and TX
 *   interrupts are not enabled until the txint() and rxint() are called.
 *
 ****************************************************************************/

static int up_attach(struct uart_dev_s *dev)
{
	(void)dev;

#if !defined(CONFIG_RT_FRAMEWORK) || (CONFIG_RT_FRAMEWORK == 0)
	//irq_attach(622, (xcpt_t)up_rxiinterrupt, NULL);
	//up_enable_irq(622);
	irq_attach(627, (xcpt_t)up_rxiinterrupt, NULL);
	up_enable_irq(627);
#endif

	return OK;
}

/****************************************************************************
 * Name: up_detach
 *
 * Description:
 *   Detach UART interrupts.  This method is called when the serial port is
 *   closed normally just before the shutdown method is called. The exception
 *   is the serial console which is never shutdown.
 *
 ****************************************************************************/

static void up_detach(struct uart_dev_s *dev)
{
	(void)dev;

#if !defined(CONFIG_RT_FRAMEWORK) || (CONFIG_RT_FRAMEWORK == 0)
	//up_disable_irq(622);
	//irq_detach(622);
	up_disable_irq(627);
	irq_detach(627);
#endif
}

/****************************************************************************
 * Name: up_ioctl
 *
 * Description:
 *   All ioctl calls will be routed through this method
 *
 ****************************************************************************/

static int up_ioctl(struct file *filep, int cmd, unsigned long arg)
{
	return -ENOTTY;
}

/****************************************************************************
 * Name: up_receive
 *
 * Description:
 *   Called (usually) from the interrupt level to receive one
 *   character from the UART.  Error bits associated with the
 *   receipt are provided in the return 'status'.
 *
 ****************************************************************************/

static int up_receive(struct uart_dev_s *dev, unsigned int *status)
{
	struct up_dev_s *priv = (struct up_dev_s *)dev->priv;

	/* get reception data */
	uint32_t lur_addr = priv->uartbase + U2BX_LIN3_UART_LURDR_OFFSET;
	uint16_t lur_value = (uint16_t)getreg16(lur_addr);

	/* get error status */
	uint32_t lest_addr = priv->uartbase + U2BX_LIN3_UART_LEST_OFFSET;
	uint8_t lest_value = (uint8_t)getreg8(lest_addr);

	/* clear all error flags */
	putreg8(lest_value & 0x7D, lest_addr);

	/* return actual data */
	return (int)(lur_value & 0xFF);
}

/****************************************************************************
 * Name: up_rxint
 *
 * Description:
 *   Call to enable or disable RX interrupts
 *
 ****************************************************************************/

static void up_rxint(struct uart_dev_s *dev, bool enable)
{
	struct up_dev_s *priv = (struct up_dev_s *)dev->priv;

	if (enable)
	{
		// todo
	}
	else
	{
		// todo
	}
}

/****************************************************************************
 * Name: up_rxavailable
 *
 * Description:
 *   Return true if the receive register is not empty
 *
 ****************************************************************************/

static bool up_rxavailable(struct uart_dev_s *dev)
{
	struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
	uint32_t lst_addr = priv->uartbase + U2BX_LIN3_UART_LST_OFFSET;
	uint8_t lst_value = (uint8_t)getreg8(lst_addr) & R_RLN30_LST_URS_Msk;

	return lst_value != 0;
}

/****************************************************************************
 * Name: up_send
 *
 * Description:
 *   This method will send one byte on the UART.
 *
 ****************************************************************************/

static void up_send(struct uart_dev_s *dev, int ch)
{
	struct up_dev_s *priv = (struct up_dev_s *)dev->priv;

	/* Wait for FIFO */
	if (dev == &CONSOLE_DEV)
	{
		up_putc(ch);
		return;
	}
}

/****************************************************************************
 * Name: up_txint
 *
 * Description:
 *   Call to enable or disable TX interrupts
 *
 ****************************************************************************/

static void up_txint(struct uart_dev_s *dev, bool enable)
{
	struct up_dev_s *priv = (struct up_dev_s *)dev->priv;

	/* Issue a transmit when TDR is empty, to generate the first interrupt */
	if (up_txready(dev))
	{
		uart_xmitchars(dev);
	}
}

/****************************************************************************
 * Name: up_txready
 *
 * Description:
 *   Return true if the tranmsit data register is not full
 *
 ****************************************************************************/

static bool up_txready(struct uart_dev_s *dev)
{
	struct up_dev_s *priv = (struct up_dev_s *)dev->priv;
	uint32_t lst_addr = priv->uartbase + U2BX_LIN3_UART_LST_OFFSET;
	uint8_t lst_value = (uint8_t)getreg8(lst_addr) & (R_RLN30_LST_UTS_Msk | R_RLN30_LST_FTC_Msk);

	return lst_value == 0;
}

#if defined(CONFIG_RT_FRAMEWORK) && (CONFIG_RT_FRAMEWORK == 1)
void up_uart_rx_handler(void)
{
	struct uart_dev_s *dev = &g_uart0port;
	uint8_t data;

	if (up_rxavailable(dev))
	{
		uart_recvchars(dev);
	}

	if (up_txready(dev))
	{
		uart_xmitchars(dev);
	}
}
#else

/****************************************************************************
 * Name: up_txiinterrupt
 *
 * Description:
 *   This is the USART TX interrupt handler.
 *
 ****************************************************************************/

static int up_txiinterrupt(int irq, void *context, void *arg)
{
	// TBD
	return OK;
}

/****************************************************************************
 * Name: up_rxiinterrupt
 *
 * Description:
 *   This is the USART RX interrupt handler.
 *
 ****************************************************************************/

static int up_rxiinterrupt(int irq, void *context, void *arg)
{
	// todo
	return OK;
}

#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: u2bx_serialinit
 *
 * Description:
 *   Register serial console and serial ports.  This assumes
 *   that u2bx_earlyserialinit was called previously.
 *
 ****************************************************************************/

void rh850_serialinit(void)
{
	up_setup(&CONSOLE_DEV);
	/* Register the console */
#ifdef CONSOLE_DEV
	CONSOLE_DEV.isconsole = true;
	uart_register("/dev/console", &CONSOLE_DEV);
#endif

	/* Register all UARTs */
#ifdef TTYS0_DEV
	uart_register("/dev/ttyS0", &TTYS0_DEV);
#endif
}

/****************************************************************************
 * Name: up_putc
 *
 * Description:
 *   Provide priority, low-level access to support OS debug  writes
 *
 ****************************************************************************/

void up_putc(int ch)
{
	struct up_dev_s *priv = (struct up_dev_s *)CONSOLE_DEV.priv;

	while (!up_txready(&CONSOLE_DEV))
	{
		// todo, handle timeout
	};

	uint32_t lut_reg = priv->uartbase + U2BX_LIN3_UART_LUTDR_OFFSET;
	putreg16(ch & 0xff, lut_reg);
}
