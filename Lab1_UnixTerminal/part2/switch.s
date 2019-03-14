	.file	"switch.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	testl	%eax, %eax
	je	.L3
	cmpl	$1, %eax
	je	.L4
	jmp	.L7
.L3:
	movl	$0, -8(%rbp)
	jmp	.L5
.L4:
	movl	$1, -8(%rbp)
	jmp	.L5
.L7:
	movl	$-1, -8(%rbp)
.L5:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",@progbits
