/*  main.c  - main */

#include <xinu.h>

process	main(void)
{
// int big, small;
// big = create(mybigloop,1024,20,"process 1",0);
// resume(big);

// sleep(10);
// kprintf("%d",lifetime(big));

// small = create(mysmallloop,1024,20,"process 1",0);
// resume(small);
// kprintf("%d",lifetime(small));
// return OK;
kprintf("%d",testgreaterfirst(4,5));
}
