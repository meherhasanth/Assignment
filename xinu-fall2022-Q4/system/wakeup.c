/* wakeup.c - wakeup */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  wakeup  -  Called by clock interrupt handler to awaken processes
 *------------------------------------------------------------------------
 */
void	wakeup(void)
{
	/* Awaken all processes that have no more time to sleep */

	resched_cntl(DEFER_START);
	while (nonempty(sleepq) && (firstkey(sleepq) <= 0)) {
		
		pid32 pid = dequeue(sleepq);
	
		
		// or check if its called by call back 
		 
		if (pid<NPROC)
		{
			//NOT CALLED BY ALARMX
			ready(pid);
			//make it ready like regular process
		}
		else if ((pid > NPROC) && (pid < 3*NPROC))
		{

			if ((pid >= NPROC) && (pid < 2*NPROC))
				{
					pid = pid-NPROC;
					proctab[pid].prmakedetour =1;
					// kprintf("%d prmakedetoure is set to " ,proctab[pid].prmakedetour);
					proctab[pid].prnumalarms= proctab[pid].prnumalarms-1;

				}
			// subtract nproc
			

			if ((pid >= 2*NPROC) && (pid < 3*NPROC))
				{
					pid = pid-2*NPROC;
					proctab[pid].prmakedetour =1;
					proctab[pid].prnumalarms= proctab[pid].prnumalarms-1;

				}

		}




	}
	resched_cntl(DEFER_STOP);
	return;
}
