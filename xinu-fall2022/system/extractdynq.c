
#include <xinu.h>
// extern struct mfeedbqx dynqueue[];

pid32 extractdynq(void)
{


    int data=inspectmaxprio();

    if (data==-1)
    {
        return SYSERR;
    }

    int val=dynqueue[data].head;
    int retval =dynqueue[data].fifoqueue[val];
    dynqueue[data].head=(dynqueue[data].head+1)%NPROC;
    dynqueue[data].count=dynqueue[data].count-1;
    
    return retval;
}