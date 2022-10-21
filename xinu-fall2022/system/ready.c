/* ready.c - ready */

#include <xinu.h>

qid16	readylist;			/* Index of ready list		*/

/*------------------------------------------------------------------------
 *  ready  -  Make a process eligible for CPU service
 *------------------------------------------------------------------------
 */
status	ready(
	  pid32		pid		/* ID of process to make ready	*/
	)
{
	register struct procent *prptr;

	if (isbadpid(pid)) {
		return SYSERR;
	}

	/* Set process state to indicate ready and add to ready list */

	prptr = &proctab[pid];

	prptr->prstate = PR_READY;
	prptr->prreadystart=getticks();
	// insert(pid, readylist, prptr->prprio);
	// here
	insertdynq(prptr->prprio,pid);
	// kprintf("\n process added to dynq\n");
	// kprintf("\n prioirty %d of processes in ready is %d \n",prptr->prprio,dynqueue[prptr->prprio].count);
	resched();

	return OK;
}
