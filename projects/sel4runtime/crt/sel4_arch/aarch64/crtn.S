/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
.section .init
	ldp x29, x30, [sp], #16
	ret

.section .fini
	ldp x29, x30, [sp], #16
	ret
