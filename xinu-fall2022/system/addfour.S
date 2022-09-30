        .text
        .globl addfour

addfour:
        pushl   %ebp
        movl    %esp,%ebp
        pushfl
        pushl   %ebx
        movl    8(%ebp),%eax
        movl    12(%ebp),%ebx
        movl    16(%ebp),%ecx
        movl    20(%ebp),%edx
        addl    %ebx,%eax       
        addl    %ecx,%eax
        addl    %edx,%eax
        popl    %ebx
        popfl
        movl    (%esp),%ebp
        add     $4,%esp
        ret
