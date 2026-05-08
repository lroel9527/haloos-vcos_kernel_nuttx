/****************************************************************************
 * arch/renesas/src/common/rh850_internal.h
 ****************************************************************************/

#ifndef ___ARCH_RH850_SRC_COMMON_UP_INTERNAL_H
#define ___ARCH_RH850_SRC_COMMON_UP_INTERNAL_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#ifndef __ASSEMBLY__
#  include <nuttx/compiler.h>
#  include <stdint.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Determine which (if any) console driver to use.  NOTE that the naming
 * implies that the console is a serial driver.  That is usually the case,
 * however, if no UARTs are enabled, the console could also be provided
 * through some other device, such as an LCD.  Architecture-specific logic
 * will have to detect that case.
 *
 * If a console is enabled and no other console device is specified, then
 * a serial console is assumed.
 */

#ifndef CONFIG_DEV_CONSOLE
#  undef  USE_SERIALDRIVER
#  undef  USE_EARLYSERIALINIT
#else
#  if defined(CONFIG_CONSOLE_SYSLOG)
#    undef  USE_SERIALDRIVER
#    undef  USE_EARLYSERIALINIT
#  else
#    define USE_SERIALDRIVER 1
#    define USE_EARLYSERIALINIT 1
#  endif
#endif

/* If some other device is used as the console, then the serial driver may
 * still be needed.  Let's assume that if the upper half serial driver is
 * built, then the lower half will also be needed.  There is no need for
 * the early serial initialization in this case.
 */

#if !defined(USE_SERIALDRIVER) && defined(CONFIG_STANDARD_SERIAL)
#  define USE_SERIALDRIVER 1
#endif

/* Check if an interrupt stack size is configured */

#ifndef CONFIG_ARCH_INTERRUPTSTACK
#  define CONFIG_ARCH_INTERRUPTSTACK 0
#endif

/* The SH stack must be aligned at word (4 byte) boundaries. If necessary
 * frame_size must be rounded up to the next boundary
 */

#define STACK_ALIGNMENT     4

/* Stack alignment macros */

#define STACK_ALIGN_MASK    (STACK_ALIGNMENT - 1)
#define STACK_ALIGN_DOWN(a) ((a) & ~STACK_ALIGN_MASK)
#define STACK_ALIGN_UP(a)   (((a) + STACK_ALIGN_MASK) & ~STACK_ALIGN_MASK)

#define rh850_savestate(regs)  rh850_copystate(regs, up_current_regs())

#define getreg8(a)          (*(volatile uint8_t *)(a))
#define putreg8(v,a)        (*(volatile uint8_t *)(a) = (v))
#define getreg16(a)         (*(volatile uint16_t *)(a))
#define putreg16(v,a)       (*(volatile uint16_t *)(a) = (v))
#define getreg32(a)         (*(volatile uint32_t *)(a))
#define putreg32(v,a)       (*(volatile uint32_t *)(a) = (v))

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__
typedef void (*up_vector_t)(void);
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifndef __ASSEMBLY__
/* This is the beginning of heap as provided from up_head.S.
 * This is the first address in DRAM after the loaded
 * program+bss+idle stack.  The end of the heap is
 * CONFIG_RAM_END
 */

#endif

/* Address of the saved user stack pointer */

#ifndef __ASSEMBLY__
#  if CONFIG_ARCH_INTERRUPTSTACK > 3
     extern uint8_t g_intstackalloc[];
     extern uint8_t g_intstacktop[];
#  endif
#endif

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifndef __ASSEMBLY__

/* Defined in files with the same name as the function */

void rh850_copystate(uint32_t *dest, uint32_t *src);
void rh850_dataabort(uint32_t *regs);
void rh850_decodeirq(uint32_t *regs);
uint32_t *rh850_doirq(int irq, uint32_t *regs);
void rh850_fullcontextrestore(uint32_t *regs) noreturn_function;
void rh850_syscall0(uint32_t *regs,uint32_t *saveregs) noreturn_function;
void rh850_prefetchabort(uint32_t *regs);
void rh850_sigdeliver(void);
// void rh850_syscall(uint32_t *regs);
void rh850_lowputc(char ch);
void rh850_lowputs(const char *str);

/* Defined in xyz_vectors.S */

void rh850_vectorundefinsn(void);
void rh850_vectorswi(void);
void rh850_vectorprefetch(void);
void rh850_vectordata(void);
void rh850_vectoraddrexcptn(void);
void rh850_vectorirq(void);
void rh850_vectorfiq(void);

/* Defined in xyz_serial.c */

#ifdef USE_EARLYSERIALINIT
void rh850_earlyconsoleinit(void);
#endif

#ifdef USE_SERIALDRIVER
void rh850_serialinit(void);
#endif

void rh850_ioportinit(void);

void rh850_lowputc(char ch);

/* Defined in board/xyz_lcd.c */

#ifdef CONFIG_SLCD_CONSOLE
void rh850_lcdinit(void);
void rh850_lcdputc(char ch);
#else
#  define rh850_lcdinit()
#  define rh850_lcdputc(ch)
#endif

/* Defined in board/xyz_network.c */

#if defined(CONFIG_NET) && !defined(CONFIG_NETDEV_LATEINIT)
void rh850_netinitialize(void);
#else
#  define rh850_netinitialize()
#endif

/* USB */

#ifdef CONFIG_USBDEV
void rh850_usbinitialize(void);
void rh850_usbuninitialize(void);
#else
#  define rh850_usbinitialize()
#  define rh850_usbuninitialize()
#endif

#endif /* __ASSEMBLY__ */
#endif /* ___ARCH_RH850_SRC_COMMON_UP_INTERNAL_H */
