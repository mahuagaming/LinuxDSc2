/*
 *  linux/arch/arm/lib/io-readsl.S
 *
 *  Copyright (C) 1995-2000 Russell King
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/linkage.h>
#include <asm/assembler.h>
#include <linux/config.h>

ENTRY(__raw_readsl)
		teq	r2, #0		@ do we have to check for the zero len?
		moveq	pc, lr
		ands	ip, r1, #3
		bne	3f

		subs	r2, r2, #4
		bmi	2f
		stmfd	sp!, {r4, lr}
1:		ldr	r3, [r0, #0]
		ldr	r4, [r0, #0]
		ldr	ip, [r0, #0]
		ldr	lr, [r0, #0]
		subs	r2, r2, #4
		stmia	r1!, {r3, r4, ip, lr}
		bpl	1b
		ldmfd	sp!, {r4, lr}
2:		movs	r2, r2, lsl #31
		ldrcs	r3, [r0, #0]
		ldrcs	ip, [r0, #0]
		stmcsia	r1!, {r3, ip}
		ldrne	r3, [r0, #0]
		strne	r3, [r1, #0]
		mov	pc, lr

3:		ldr	r3, [r0]
		cmp	ip, #2
		mov	ip, r3, get_byte_0
#ifdef CONFIG_NDS_ROM8BIT
		swpb	ip, ip, [r1]
		add	r1, r1, #1
#else
		strb	ip, [r1], #1
#endif
		bgt	6f
		mov	ip, r3, get_byte_1
#ifdef CONFIG_NDS_ROM8BIT
		swpb	ip, ip, [r1]
		add	r1, r1, #1
#else
		strb	ip, [r1], #1
#endif
		beq	5f
		mov	ip, r3, get_byte_2
#ifdef CONFIG_NDS_ROM8BIT
		swpb	ip, ip, [r1]
		add	r1, r1, #1
#else
		strb	ip, [r1], #1
#endif
4:		subs	r2, r2, #1
		mov	ip, r3, pull #24
		ldrne	r3, [r0]
		orrne	ip, ip, r3, push #8
		strne	ip, [r1], #4
		bne	4b
		b	8f

5:		subs	r2, r2, #1
		mov	ip, r3, pull #16
		ldrne	r3, [r0]
		orrne	ip, ip, r3, push #16
		strne	ip, [r1], #4
		bne	5b
		b	7f

6:		subs	r2, r2, #1
		mov	ip, r3, pull #8
		ldrne	r3, [r0]
		orrne	ip, ip, r3, push #24
		strne	ip, [r1], #4
		bne	6b

		mov	r3, ip, get_byte_2
#ifdef CONFIG_NDS_ROM8BIT
		add	r2, r1, #2
		swpb	r3, r3, [r2]
#else
		strb	r3, [r1, #2]
#endif
7:		mov	r3, ip, get_byte_1
#ifdef CONFIG_NDS_ROM8BIT
		add	r2, r1, #1
		swpb	r3, r3, [r2]
#else
		strb	r3, [r1, #1]
#endif
8:		mov	r3, ip, get_byte_0
#ifdef CONFIG_NDS_ROM8BIT
		swpb	r3, r3, [r1]
#else
		strb	r3, [r1, #0]
#endif
		mov	pc, lr
