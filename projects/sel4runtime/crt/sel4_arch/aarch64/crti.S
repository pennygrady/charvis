/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
.section .init
.global _init
_init:
	stp x29, x30, [sp, -16]!
	mov x29, sp

.section .fini
.global _fini
_fini:
	stp x29, x30, [sp, -16]!
	mov x29, sp