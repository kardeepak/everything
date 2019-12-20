	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	lea	rdi, [rip + L_.str]
	lea	rsi, [rbp - 4]
	lea	rdx, [rbp - 8]
	mov	al, 0
	call	_scanf
	mov	ecx, dword ptr [rbp - 4]
	mov	dword ptr [rbp - 16], eax ## 4-byte Spill
	mov	eax, ecx
	cdq
	idiv	dword ptr [rbp - 8]
	mov	dword ptr [rbp - 12], edx
	mov	esi, dword ptr [rbp - 12]
	lea	rdi, [rip + L_.str.1]
	mov	al, 0
	call	_printf
	xor	ecx, ecx
	mov	dword ptr [rbp - 20], eax ## 4-byte Spill
	mov	eax, ecx
	add	rsp, 32
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d %d"

L_.str.1:                               ## @.str.1
	.asciz	"%d\n"


.subsections_via_symbols
