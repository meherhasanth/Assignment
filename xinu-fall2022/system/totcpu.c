#include <xinu.h>

uint32 totcpu(pid32 pid){

    if (isbadpid(pid)) {
     return SYSERR;
    }
   

    uint32 a =  proctab[pid].prtotalcpu/1000;

    return a;
}