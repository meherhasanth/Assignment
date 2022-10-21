/*  main.c  - main */

#include <xinu.h>

process	main(void)
{

// kprintf("\nThis is main running");
// pid32 a=createtsx(cpubound,2048,"bigloop",0);
// resume(a);
//kprintf("%d\n",totcpu(a));
// pid32 b=createtsx(mybigloop2,2048,"bigloop2",0);
// resume(b);
// //kprintf("%d\n",totcpu(b));
// pid32 c=create(mybigloop,2048,20,"bigloop3",0);
// resume(c);

// pid32 d=create(mybigloop,2048,20,"bigloop4",0);
// resume(d);

    pid32 a=createtsx(cpubound,2048,"bigloop1",0);
    resume(a);
    pid32 b=createtsx(cpubound,2048,"bigloop2",0);
    resume(b);
    pid32 c=createtsx(cpubound,2048,"bigloop3",0);
    resume(c);
    pid32 d=createtsx(cpubound,2048,"bigloop4",0);
    resume(d);
    pid32 e=createtsx(iobound,2048,"bigloop5",0);
    resume(e);
    pid32 f=createtsx(iobound,2048,"bigloop6",0);
    resume(f);
    pid32 g=createtsx(iobound,2048,"bigloop7",0);
    resume(g);
    pid32 h=createtsx(iobound,2048,"bigloop8",0);
    resume(h);




}


