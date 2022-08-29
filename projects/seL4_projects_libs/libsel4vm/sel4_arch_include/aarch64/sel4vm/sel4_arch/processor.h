/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#pragma once

#include <sel4/sel4.h>
#include <sel4vm/arch/processor.h>

typedef enum processor_mode {
    PMODE_EL3h = 0b1101,
    PMODE_EL3t = 0b1100,
    PMODE_EL2h = 0b1001,
    PMODE_EL2t = 0b1000,
    PMODE_EL1h = 0b0101,
    PMODE_EL1t = 0b0100,
    PMODE_EL0t = 0b0000
} processor_mode_t;

#define seL4_UnknownSyscall_ARG0 seL4_UnknownSyscall_X0

/* HSR Exception Value */
#define HSR_UNKNOWN_EXCEPTION       (0x0)
#define HSR_WFx_EXCEPTION           (0x1)
#define HSR_CP15_32_EXCEPTION       (0x3)
#define HSR_CP15_64_EXCEPTION       (0x4)
#define HSR_CP14_32_EXCEPTION       (0x5)
#define HSR_CP14_LC_32_EXCEPTION    (0x6)
#define HSR_SIMD_EXCEPTION          (0x7)
#define HSR_CP10_EXCEPTION          (0x8)
#define HSR_CP14_EXCEPTION          (0xC)
#define HSR_ILLEGAL_EXCEPTION       (0xE)
#define HSR_SVC_32_EXCEPTION        (0x11)
#define HSR_HVC_32_EXCEPTION        (0x12)
#define HSR_SMC_32_EXCEPTION        (0x13)
#define HSR_SVC_64_EXCEPTION        (0x15)
#define HSR_HVC_64_EXCEPTION        (0x16)
#define HSR_SMC_64_EXCEPTION        (0x17)
#define HSR_SYSREG_64_EXCEPTION     (0x18)
#define HSR_IMPL_DEF_EXCEPTION      (0x1f)
#define HSR_IABT_LOW_EXCEPTION      (0x20)
#define HSR_IABT_CURR_EXCEPTION     (0x21)
#define HSR_PC_ALIGN_EXCEPTION      (0x22)
#define HSR_DABT_LOW_EXCEPTION      (0x24)
#define HSR_DABT_CUR_EXCEPTION      (0x25)
#define HSR_SP_ALIGN_EXCEPTION      (0x26)
#define HSR_FP32_EXCEPTION          (0x28)
#define HSR_FP64_EXCEPTION          (0x2C)
#define HSR_SERROR_EXCEPTION        (0x2F)
#define HSR_BRK_LOW_EXCEPTION       (0x30)
#define HSR_BRK_CUR_EXCEPTION       (0x31)
#define HSR_SWSTEP_LOW_EXCEPTION    (0x32)
#define HSR_SWSTEP_CUR_EXCEPTION    (0x33)
#define HSR_WATCHPT_LOW_EXCEPTION   (0x34)
#define HSR_WATCHPT_CUR_EXCEPTION   (0x35)
#define HSR_SWBRK_32_EXCEPTION      (0x38)
#define HSW_VECTOR_32_EXCEPTION     (0x3a)
#define HSR_SWBRK_64_EXCEPTION      (0x3c)
/* Remaining values (0x3d - 0x3f) are reserved */

#define HSR_REASON_ENTRY(HSR) [HSR] = #HSR

static const char *hsr_reasons[HSR_MAX_EXCEPTION] = {
    [0 ... HSR_MAX_EXCEPTION - 1] = "Unknown Exception Class",
    HSR_REASON_ENTRY(HSR_UNKNOWN_EXCEPTION),
    HSR_REASON_ENTRY(HSR_WFx_EXCEPTION),
    HSR_REASON_ENTRY(HSR_CP15_32_EXCEPTION),
    HSR_REASON_ENTRY(HSR_CP15_64_EXCEPTION),
    HSR_REASON_ENTRY(HSR_CP14_32_EXCEPTION),
    HSR_REASON_ENTRY(HSR_CP14_LC_32_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SIMD_EXCEPTION),
    HSR_REASON_ENTRY(HSR_CP10_EXCEPTION),
    HSR_REASON_ENTRY(HSR_CP14_EXCEPTION),
    HSR_REASON_ENTRY(HSR_ILLEGAL_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SVC_32_EXCEPTION),
    HSR_REASON_ENTRY(HSR_HVC_32_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SMC_32_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SVC_64_EXCEPTION),
    HSR_REASON_ENTRY(HSR_HVC_64_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SMC_64_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SYSREG_64_EXCEPTION),
    HSR_REASON_ENTRY(HSR_IMPL_DEF_EXCEPTION),
    HSR_REASON_ENTRY(HSR_IABT_LOW_EXCEPTION),
    HSR_REASON_ENTRY(HSR_IABT_CURR_EXCEPTION),
    HSR_REASON_ENTRY(HSR_PC_ALIGN_EXCEPTION),
    HSR_REASON_ENTRY(HSR_DABT_LOW_EXCEPTION),
    HSR_REASON_ENTRY(HSR_DABT_CUR_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SP_ALIGN_EXCEPTION),
    HSR_REASON_ENTRY(HSR_FP32_EXCEPTION),
    HSR_REASON_ENTRY(HSR_FP64_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SERROR_EXCEPTION),
    HSR_REASON_ENTRY(HSR_BRK_LOW_EXCEPTION),
    HSR_REASON_ENTRY(HSR_BRK_CUR_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SWSTEP_LOW_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SWSTEP_CUR_EXCEPTION),
    HSR_REASON_ENTRY(HSR_WATCHPT_LOW_EXCEPTION),
    HSR_REASON_ENTRY(HSR_WATCHPT_CUR_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SWBRK_32_EXCEPTION),
    HSR_REASON_ENTRY(HSW_VECTOR_32_EXCEPTION),
    HSR_REASON_ENTRY(HSR_SWBRK_64_EXCEPTION)
};