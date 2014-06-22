/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_CM3_DWT_H
#define LIBOPENCM3_CM3_DWT_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/cm3/memorymap.h>

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define DWT_CTRL			MMIO32(DWT_BASE + 0x00)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

#define DWT_CYCCNT			MMIO32(DWT_BASE + 0x04)
#define DWT_CPICNT			MMIO32(DWT_BASE + 0x08)
#define DWT_EXCCNT			MMIO32(DWT_BASE + 0x0C)
#define DWT_SLEEPCNT			MMIO32(DWT_BASE + 0x10)
#define DWT_LSUCNT			MMIO32(DWT_BASE + 0x14)
#define DWT_FOLDCNT			MMIO32(DWT_BASE + 0x18)

#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) */

#define DWT_PCSR			MMIO32(DWT_BASE + 0x1C)
#define DWT_COMP(n)			MMIO32(DWT_BASE + 0x20 + (n) * 16)
#define DWT_MASK(n)			MMIO32(DWT_BASE + 0x24 + (n) * 16)
#define DWT_FUNCTION(n)			MMIO32(DWT_BASE + 0x28 + (n) * 16)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- DWT_CTRL values ---------------------------------------------------- */

#define DWT_CTRL_NUMCOMP_SHIFT		28
#define DWT_CTRL_NUMCOMP		(0x0F << DWT_CTRL_NUMCOMP_SHIFT)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

#define DWT_CTRL_NOTRCPKT		(1 << 27)
#define DWT_CTRL_NOEXTTRIG		(1 << 26)
#define DWT_CTRL_NOCYCCNT		(1 << 25)
#define DWT_CTRL_NOPRFCCNT		(1 << 24)

#define DWT_CTRL_CYCEVTENA		(1 << 22)
#define DWT_CTRL_FOLDEVTENA		(1 << 21)
#define DWT_CTRL_LSUEVTENA		(1 << 20)
#define DWT_CTRL_SLEEPEVTENA		(1 << 19)
#define DWT_CTRL_EXCEVTENA		(1 << 18)
#define DWT_CTRL_CPIEVTENA		(1 << 17)
#define DWT_CTRL_EXCTRCENA		(1 << 16)
#define DWT_CTRL_PCSAMPLENA		(1 << 12)

#define DWT_CTRL_SYNCTAP_SHIFT		10
#define DWT_CTRL_SYNCTAP		(3 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_DISABLED	(0 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT24		(1 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT26		(2 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT28		(3 << DWT_CTRL_SYNCTAP_SHIFT)

#define DWT_CTRL_CYCTAP			(1 << 9)

#define DWT_CTRL_POSTCNT_SHIFT		5
#define DWT_CTRL_POSTCNT		(0x0F << DWT_CTRL_POSTCNT_SHIFT)

#define DWT_CTRL_POSTPRESET_SHIFT	1
#define DWT_CTRL_POSTPRESET		(0x0F << DWT_CTRL_POSTPRESET_SHIFT)

#define DWT_CTRL_CYCCNTENA		(1 << 0)

#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) */

/* --- DWT_MASK(x) values -------------------------------------------------- */

#define DWT_MASKx_MASK			0x0F

/* --- DWT_FUNCTION(x) values ---------------------------------------------- */

#define DWT_FUNCTIONx_MATCHED		(1 << 24)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

#define DWT_FUNCTIONx_DATAVADDR1_SHIFT	16
#define DWT_FUNCTIONx_DATAVADDR1	(15 << DWT_FUNCTIONx_DATAVADDR1_SHIFT)

#define DWT_FUNCTIONx_DATAVADDR0_SHIFT	12
#define DWT_FUNCTIONx_DATAVADDR0	(15 << DWT_FUNCTIONx_DATAVADDR0_SHIFT)

#define DWT_FUNCTIONx_DATAVSIZE_SHIFT	10
#define DWT_FUNCTIONx_DATAVSIZE		(3 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_BYTE	(0 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_HALF	(1 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_WORD	(2 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)

#define DWT_FUNCTIONx_LNK1ENA		(1 << 9)
#define DWT_FUNCTIONx_DATAVMATCH	(1 << 8)
#define DWT_FUNCTIONx_CYCMATCH		(1 << 7)
#define DWT_FUNCTIONx_EMITRANGE		(1 << 5)

#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) */

#define DWT_FUNCTIONx_FUNCTION				15
#define DWT_FUNCTIONx_FUNCTION_DISABLED			0

/* Those defined only on ARMv6 */
#if defined(__ARM_ARCH_6M__)

#define DWT_FUNCTIONx_FUNCTION_PCWATCH			4
#define DWT_FUNCTIONx_FUNCTION_DWATCH_R			5
#define DWT_FUNCTIONx_FUNCTION_DWATCH_W			6
#define DWT_FUNCTIONx_FUNCTION_DWATCH_RW		7

#endif /* defined(__ARM_ARCH_6M__)*/

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

bool dwt_enable_cycle_counter(void);
uint32_t dwt_read_cycle_counter(void);

END_DECLS

#endif /* LIBOPENCM3_CM3_DWT_H */
