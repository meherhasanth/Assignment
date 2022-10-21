/* resched.c - resched, resched_cntl */

#include <xinu.h>

uint64 currstart;
uint64 currstop;
uint64 readystart;
int flag=0;

struct	defer Defer;

/*------------------------------------------------------------------------
 *  resched  -  Reschedule processor to highest priority eligible process
 *------------------------------------------------------------------------
 */
void	resched(void)		/* Assumes interrupts are disabled	*/
{
	struct procent *ptold;	/* Ptr to table entry for old process	*/
	struct procent *ptnew;	/* Ptr to table entry for new process	*/

	/* If rescheduling is deferred, record attempt and return */

	if (Defer.ndefers > 0) {
		Defer.attempt = TRUE;
		return;
	}

	/* Point to process table entry for the current (old) process */

	ptold = &proctab[currpid];
    currstop=getticks();
	ptold->prtotalcpu += ((uint32)(currstop-currstart))/389;
	if (ptold->prstate == PR_CURR) {  /* Process remains eligible */
		if (ptold->prprio > inspectmaxprio()) {
			currstart=getticks(); //galat hai
			return;
		}

		/* Old process will no longer remain current */
		
		ptold->prstate = PR_READY;
		ptold->prpreemptcount1=ptold->prpreemptcount1+1;
		currstop=getticks();

		// insert(currpid, readylist, ptold->prprio);
		insertdynq(ptold->prprio,currpid);

		
	}

	

	/* Force context switch to highest priority ready process */

	// currpid = dequeue(readylist);
	currpid = extractdynq();

	currpid = currpid==-1?0:currpid;

	ptnew = &proctab[currpid];
	if (ptnew->remainingquntumsize>0 )
	{
		preempt=ptnew->remainingquntumsize; // saved the remaining quantum 
		ptnew->remainingquntumsize=0;       // reset the remaining quantum to 0
	}
	ptnew->prstate = PR_CURR;
	currstart=getticks();
	uint32 val=(uint32)(currstart-ptnew->prreadystart)/389;
	if (val/1000>ptnew->maxresponsetime)
	{
		ptnew->maxresponsetime=val/1000;
		// ptnew->maxresponsetime=val/(double)389000;
	}
	ptnew->prtotalresponse=ptnew->prtotalresponse+val;

	
	if (flag==1)
	{
		ptold->prpreemptcount2=ptold->prpreemptcount2+1;
		flag=0;
	}

	// preempt = QUANTUM;		/* Reset time slice for process	*/
	ctxsw(&ptold->prstkptr, &ptnew->prstkptr);
	ptnew->prcurrcount=ptnew->prcurrcount+1;

	
	/* Old process returns here when resumed */



	return;
}

/*------------------------------------------------------------------------
 *  resched_cntl  -  Control whether rescheduling is deferred or allowed
 *------------------------------------------------------------------------
 */
status	resched_cntl(		/* Assumes interrupts are disabled	*/
	  int32	defer		/* Either DEFER_START or DEFER_STOP	*/
	)
{
	switch (defer) {

	    case DEFER_START:	/* Handle a deferral request */

		if (Defer.ndefers++ == 0) {
			Defer.attempt = FALSE;
		}
		return OK;

	    case DEFER_STOP:	/* Handle end of deferral */
		if (Defer.ndefers <= 0) {
			return SYSERR;
		}
		if ( (--Defer.ndefers == 0) && Defer.attempt ) {
			resched();
			flag=1;
		}
		return OK;

	    default:
		return SYSERR;
	}
}
