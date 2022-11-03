
#include <xinu.h>


syscall receivex(pid32 *pidptr, char *buf, uint16 len )

{
    wait(proctab[currpid].pripc);
	if ( proctab[currpid].prrecvlen==0) {

        // kprintf("block1 \n");
		proctab[currpid].prstate = PR_RECV;
        signal(proctab[currpid].pripc);
		resched();		/* Block until message arrives	*/
        wait(proctab[currpid].pripc);
	}

    strcpy(buf,proctab[currpid].prrecvbuf);

    *pidptr = proctab[currpid].prsenderpid;
    proctab[currpid].prsenderpid=0;
    proctab[currpid].prrecvlen=0;



    if (proctab[currpid].prblockedsender!=0)
    {
        // kprintf("block2 \n");
        pid32 blockedpid = proctab[currpid].prblockedsender;
        strcpy(proctab[currpid].prrecvbuf,proctab[blockedpid].prsndbuf);
        proctab[currpid].prrecvlen=strlen(proctab[blockedpid].prsndbuf);
        proctab[currpid].prblockedsender=0;
        proctab[currpid].prsenderpid=blockedpid;
        ready(blockedpid);
        proctab[blockedpid].prblockonreceiver=0;
    
    }
    signal(proctab[currpid].pripc);
    return OK;

}