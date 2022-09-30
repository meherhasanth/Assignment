
#include<xinu.h>

void myhellow(void)
{
    
    	
    kprintf("\nI'm K MEHER HASANTH and my username is kmeherha.\n");
	kprintf("Test process running code of main():\n");
	
	kprintf("pid of the process is\n");
	kprintf("%d",currpid);
	
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
