	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function main
LCPI0_0:
	.quad	4613937818241073152     ## double 3
LCPI0_1:
	.quad	4611686018427387904     ## double 2
LCPI0_2:
	.quad	4616189618054758400     ## double 4
LCPI0_3:
	.quad	4487126258331716666     ## double 1.0E-8
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI0_4:
	.quad	9223372036854775807     ## double NaN
	.quad	9223372036854775807     ## double NaN
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movsd	LCPI0_1(%rip), %xmm0    ## xmm0 = mem[0],zero
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	sqrtsd	%xmm0, %xmm1
	divsd	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	callq	_asin
	movsd	LCPI0_1(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	LCPI0_0(%rip), %xmm2    ## xmm2 = mem[0],zero
	movsd	LCPI0_2(%rip), %xmm3    ## xmm3 = mem[0],zero
	mulsd	%xmm0, %xmm3
	movsd	%xmm3, -24(%rbp)
	sqrtsd	%xmm2, %xmm0
	divsd	%xmm1, %xmm0
	callq	_asin
	movsd	LCPI0_0(%rip), %xmm1    ## xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	movsd	%xmm1, -32(%rbp)
	movsd	-24(%rbp), %xmm0        ## xmm0 = mem[0],zero
	ucomisd	-32(%rbp), %xmm0
	jne	LBB0_2
	jp	LBB0_2
## %bb.1:
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	jmp	LBB0_3
LBB0_2:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -40(%rbp)         ## 4-byte Spill
LBB0_3:
	movsd	LCPI0_3(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	-24(%rbp), %xmm1        ## xmm1 = mem[0],zero
	subsd	-32(%rbp), %xmm1
	movaps	LCPI0_4(%rip), %xmm2    ## xmm2 = [nan,nan]
	pand	%xmm2, %xmm1
	ucomisd	%xmm1, %xmm0
	jbe	LBB0_5
## %bb.4:
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	jmp	LBB0_6
LBB0_5:
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -48(%rbp)         ## 4-byte Spill
LBB0_6:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.globl	_eps                    ## @eps
	.p2align	3
_eps:
	.quad	4487126258331716666     ## double 1.0E-8

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"true"

L_.str.1:                               ## @.str.1
	.asciz	"false\n"

L_.str.2:                               ## @.str.2
	.asciz	"false"


.subsections_via_symbols
