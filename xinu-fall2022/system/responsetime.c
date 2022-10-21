#include <xinu.h>

uint32 resptime(pid32 pid){

    if (isbadpid(pid)) {
     return SYSERR;
    }
   

    unsigned short a = ((uint32)proctab[pid].prtotalresponse)/((proctab[pid].prcurrcount)*389);
    return a;
}