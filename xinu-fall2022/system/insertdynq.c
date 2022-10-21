#include <xinu.h>


short insertdynq(pri16 priority,pid32 pid)

{


    if (dynqueue[priority].count>100)
    {
        return SYSERR;
    }

    dynqueue[priority].fifoqueue[dynqueue[priority].tail]=pid;
    dynqueue[priority].tail=(dynqueue[priority].tail+1)%NPROC;
    dynqueue[priority].count=dynqueue[priority].count+1;
    
    return dynqueue[priority].count;
}