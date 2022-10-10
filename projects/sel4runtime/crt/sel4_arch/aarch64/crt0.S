/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
.section .text
.global _start
_start:
	mov x29, #0
	mov x30, #0

	mov x0, sp
	bl __sel4_start_c

	/* should not return */
1:
	b 1b

