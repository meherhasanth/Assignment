	.file	"alarmx.c"
	.text
	.globl	alarmx
	.type	alarmx, @function
alarmx:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	jne	.L2
	movl	$-1, %eax
	jmp	.L3
.L2:
	movl	currpid, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movw	14(%eax), %ax
	cmpw	$1, %ax
	jbe	.L4
	movl	$-1, %eax
	jmp	.L3
.L4:
	movl	-12(%ebp), %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movw	14(%eax), %ax
	testw	%ax, %ax
	jne	.L5
	movl	8(%ebp), %edx
	movw	sleepq, %ax
	cwtl
	movl	-12(%ebp), %ecx
	addl	$100, %ecx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
	call	insertd
.L5:
	movl	-12(%ebp), %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movw	14(%eax), %ax
	cmpw	$1, %ax
	jne	.L6
	movl	8(%ebp), %edx
	movw	sleepq, %ax
	cwtl
	movl	-12(%ebp), %ecx
	addl	$200, %ecx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
	call	insertd
.L6:
	movl	-12(%ebp), %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movw	14(%eax), %ax
	incl	%eax
	movl	-12(%ebp), %edx
	sall	$6, %edx
	addl	$proctab+48, %edx
	movw	%ax, 14(%edx)
	movl	-12(%ebp), %eax
	sall	$6, %eax
	leal	proctab+56(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, (%edx)
	movl	$0, %eax
.L3:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	alarmx, .-alarmx
	.ident	"GCC: (Ubuntu 4.8.5-4ubuntu8) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
