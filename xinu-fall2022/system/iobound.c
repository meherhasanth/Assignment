#include <xinu.h>

void iobound(void)
{
    uint32 a = vfineclkcounter;

    int i;
    while(vfineclkcounter<a+STOPTIME)
    {
        for (i=0;i<6000000;i++);
        sleepms(80);



    }
    kprintf("\niobound id: %d\n,totcpu: %d\n,usercpu: %d\n,resptime: %d\n,maxresptime: %d\n,contextswitches: %d\n,preempt1: %d\n,preempt2: %d\n",currpid,totcpu(currpid),proctab[currpid].prusercpu,resptime(currpid),proctab[currpid].maxresponsetime,proctab[currpid].prcurrcount,proctab[currpid].prpreemptcount1,proctab[currpid].prpreemptcount2);

}