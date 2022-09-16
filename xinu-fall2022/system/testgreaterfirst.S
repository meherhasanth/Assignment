        .text
        .globl testgreaterfirst

testgreaterfirst:
        pushl   %ebp
        movl    %esp,%ebp
        pushfl
        pushl   %ebx
        pushl   12(%ebp) # address of arg 2
        pushl   8(%ebp) # address of arg 1
        call    greaterfirst2
        popl   %ecx 
        popl   %ecx
        popl   %ebx
        popfl 
        popl   %ebp
        ret
