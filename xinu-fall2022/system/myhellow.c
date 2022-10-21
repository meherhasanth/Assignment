
#include<xinu.h>

void myhellow(void)
{
    	
    kprintf("\nI'm K MEHER HASANTH and my username is kmeherha.\n");
	kprintf("Test process running code in my hellow:\n");
	
/*	kprintf("pid of the process is\n");
	kprintf("%d\n",currpid);
	kprintf("hi\n"); */

	// pid32 a=createtsx(mybigloop,2048,"bigloop",0);
	// resume(a);	

	// pid32 b=createtsx(mybigloop,2048,"bigloop",0);
	// resume(b);	


	// int i =0;
	// for (i=0;i<10;i++)
	// {
	// 	kprintf("tq exp is: %d\n",dyndisp[i].tqexp);
	// 	kprintf("sleepret  is: %d\n",dyndisp[i].slpret);
	// 	kprintf("quantum is: %d\n",dyndisp[i].quantum);
	// 	kprintf("quantum is: %d\n",dyndisp[i].quantum);


	// 	kprintf("queue head is : %d\n",dynqueue[i].head);
	// 	kprintf("queue tail is : %d\n",dynqueue[i].tail);


	// }


	/* Run the Xinu shell */

	//recvclr();
	//create2(myfunc, 8192, 50, "shell", 1, CONSOLE);

	/* Wait for shell to exit and recreate it */

	/*while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}*/
	

}
