	.file	"executedetour.c"
	.text
	.globl	executedetour
	.type	executedetour, @function
executedetour:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	currpid, %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movl	12(%eax), %eax
	andl	$65535, %eax
	movl	%eax, -4(%ebp)
	cmpl	$0, -4(%ebp)
	jne	.L2
	jmp	.L1
.L2:
	movl	currpid, %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movw	$0, 12(%eax)
	movl	currpid, %eax
	sall	$6, %eax
	addl	$proctab+56, %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	$restoreregs, -12(%ebp)
#APP
# 17 "../system/executedetour.c" 1
	pushl -12(%ebp)
# 0 "" 2
# 18 "../system/executedetour.c" 1
	pushl $0x00000200
# 0 "" 2
# 19 "../system/executedetour.c" 1
	pushl %cs
# 0 "" 2
# 20 "../system/executedetour.c" 1
	pushl -8(%ebp)
# 0 "" 2
# 21 "../system/executedetour.c" 1
	iret
# 0 "" 2
#NO_APP
.L1:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	executedetour, .-executedetour
	.ident	"GCC: (Ubuntu 4.8.5-4ubuntu8) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
