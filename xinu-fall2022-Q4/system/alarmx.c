#include <xinu.h>
#define prmakedetour 0; 
syscall alarmx(uint32 timeval, void * ftn)
{
    intmask 	mask;
    mask = disable();
    if (timeval<=0)
    {
        restore(mask);
        return SYSERR;
    }
    // sleep(timeval);

    int a = currpid;

    if (proctab[a].prnumalarms>=2)
    {   
        restore(mask);

        return SYSERR;
    }

    if (proctab[a].prnumalarms==0)
    {
        insertd(NPROC+a,sleepq,timeval);

    }
    if (proctab[a].prnumalarms==1)
    {
        insertd(2*NPROC+a,sleepq,timeval);

    }
    proctab[a].prnumalarms=proctab[a].prnumalarms+1;
    proctab[a].prcbftn = (uint32)ftn; // registring the callback function
    restore(mask);
    return 0;
}