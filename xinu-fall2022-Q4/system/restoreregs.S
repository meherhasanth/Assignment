        .text
        .globl restoreregs

restoreregs:
    addl $24,%esp
    popal
    iret


