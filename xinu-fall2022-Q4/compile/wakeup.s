	.file	"wakeup.c"
	.text
	.globl	wakeup
	.type	wakeup, @function
wakeup:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$1, (%esp)
	call	resched_cntl
	nop
	movw	sleepq, %ax
	cwtl
	movl	queuetab+4(,%eax,8), %eax
	cmpw	$299, %ax
	jg	.L1
	jmp	.L8
.L7:
	movw	sleepq, %ax
	cwtl
	movl	%eax, (%esp)
	call	dequeue
	movl	%eax, -12(%ebp)
	cmpl	$99, -12(%ebp)
	jg	.L3
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	ready
	jmp	.L4
.L3:
	cmpl	$100, -12(%ebp)
	jle	.L4
	cmpl	$299, -12(%ebp)
	jg	.L4
	cmpl	$100, -12(%ebp)
	jle	.L5
	cmpl	$199, -12(%ebp)
	jg	.L5
	subl	$100, -12(%ebp)
	movl	-12(%ebp), %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movw	$1, 12(%eax)
	movl	-12(%ebp), %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movw	14(%eax), %ax
	decl	%eax
	movl	-12(%ebp), %edx
	sall	$6, %edx
	addl	$proctab+48, %edx
	movw	%ax, 14(%edx)
.L5:
	cmpl	$200, -12(%ebp)
	jle	.L4
	cmpl	$299, -12(%ebp)
	jg	.L4
	subl	$200, -12(%ebp)
	movl	-12(%ebp), %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movw	$1, 12(%eax)
	movl	-12(%ebp), %eax
	sall	$6, %eax
	addl	$proctab+48, %eax
	movw	14(%eax), %ax
	decl	%eax
	movl	-12(%ebp), %edx
	sall	$6, %edx
	addl	$proctab+48, %edx
	movw	%ax, 14(%edx)
.L4:
	movl	$2, (%esp)
	call	resched_cntl
	jmp	.L1
.L8:
	movw	sleepq, %ax
	cwtl
	movl	queuetab+4(,%eax,8), %eax
	cwtl
	movl	queuetab(,%eax,8), %eax
	testl	%eax, %eax
	jle	.L7
.L1:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	wakeup, .-wakeup
	.ident	"GCC: (Ubuntu 4.8.5-4ubuntu8) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
