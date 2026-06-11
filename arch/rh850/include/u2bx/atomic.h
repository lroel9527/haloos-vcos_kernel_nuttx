#ifndef __ARCH_RH850_INCLUDE_U2BX_RTFW_ATOMIC_H
#define __ARCH_RH850_INCLUDE_U2BX_RTFW_ATOMIC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <nuttx/compiler.h>
#include "atomic.h"

#pragma ghs nowarning 301

typedef volatile int32_t Atomic;

#pragma ghs endnowarning 301

static inline Atomic Os_AtomicOr(Atomic *ptr, int32_t orVal)
{
	return 0;
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_RH850_INCLUDE_U2BX_RTFW_ATOMIC_H */
