
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */
#pragma once
#include <api/invocation.h>

enum sel4_arch_invocation_label {
    ARMVSpaceClean_Data = nInvocationLabels,
    ARMVSpaceInvalidate_Data,
    ARMVSpaceCleanInvalidate_Data,
    ARMVSpaceUnify_Instruction,
#if !(defined(CONFIG_ARM_HYPERVISOR_SUPPORT) && defined(CONFIG_ARM_PA_SIZE_BITS_40))
    ARMPageUpperDirectoryMap,
#endif
#if !(defined(CONFIG_ARM_HYPERVISOR_SUPPORT) && defined(CONFIG_ARM_PA_SIZE_BITS_40))
    ARMPageUpperDirectoryUnmap,
#endif
    ARMPageDirectoryMap,
    ARMPageDirectoryUnmap,
    nSeL4ArchInvocationLabels
};