#include <xinu.h>

syscall sendx(pid32 pid, char *buf, uint16 len)

{


    wait(proctab[pid].pripc);

    if (proctab[pid].prrecvlen ==0)
    {
        // kprintf("block3 \n");
        strcpy(proctab[pid].prrecvbuf,buf);
        // kprintf(proctab[pid].prrecvbuf);
        // kprintf(buf);
        proctab[pid].prrecvlen=len;
        proctab[pid].prsenderpid=currpid;
        
        if (proctab[pid].prstate==PR_RECV)
        {
            ready(pid);
        }


    }

    else 
    {
        // kprintf("block4 \n");
        if (proctab[pid].prblockedsender!=0)
        {
            signal(proctab[pid].pripc);
            return SYSERR;
        }
        if (proctab[currpid].prsndbuflen==0)
        {
            // kprintf("block5 \n");
            
            strcpy( proctab[currpid].prsndbuf,buf);
            proctab[currpid].prsndbuflen=len;
            proctab[currpid].prblockedsender = pid; 
            proctab[currpid].prstate=PR_SENDBLOCK;
            proctab[pid].prblockedsender=currpid;
            signal(proctab[pid].pripc);
            resched();
            return OK;
        }
        else
        {
            // kprintf("block6 \n");
            signal(proctab[pid].pripc);
            return SYSERR;
        }
    }
    signal(proctab[pid].pripc);
    return OK;



}