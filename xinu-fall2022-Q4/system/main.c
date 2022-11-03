/*  main.c  - main */


#include <xinu.h>

void sndA(void), sndB(void), sndC(void), sndD(void);
pid32 recvpid;
pid32 snd1pid;
pid32 snd2pid;
pid32 snd3pid;

process	main(void) {
    
	// kprintf("\nTest process running code of main()\n");



// 	int x = alarmx(2,mybigloop);
// 	// int y = alarmx(2,mybigloop);
// 	// int z= alarmx(2,mybigloop);

// 	// kprintf("%d:z",z);

// // kprintf( " %d this is return value of alarmx\n",x);

// 	sleepms(20);
// 	int i=5000000000;
// 	while (i>0)
// 	{
// 		i--;
// 	}
	// kprintf(" falg is %d\n",proctab[currpid].prmakedetour);

	recvpid = create(sndA, 1024, 20, "process 1", 0);
	snd1pid = create(sndB, 1024, 20, "process 2", 0);
	snd2pid= create(sndC, 1024, 20, "process 2", 0);
	snd3pid= create(sndD, 1024, 20, "process 2", 0);


  	resume(snd1pid);
	resume(snd2pid);
	resume(snd3pid);


	sleepms(3000);	
	resume(recvpid);

	return OK;
}

/*------------------------------------------------------------------------
* sndA - Repeatedly emit ’A’ on the console without terminating
*------------------------------------------------------------------------
*/
void sndA(void) {
	printf("starting process sndA\n");

	pid32 *pidptr = 0;
	uint16 len = 10000;
	char buf[len];
	
	receivex(pidptr, buf, len);

	printf("recv msg - %s\n",buf);
	printf("recv msg from sender pid - %d\n", *pidptr);

	receivex(pidptr, buf, len);

	printf("recv msg - %s\n", buf);
	printf("recv msg from sender pid - %d\n", *pidptr);
}


void sndB(void) {
	printf("starting process sndB\n");

	sleepms(100);
	char buf[10] = "message 1";

	uint32 output = sendx(recvpid, buf, 10);
	printf("send B returned with out - %d\n", output);	
 }


void sndC(void) {
	printf("starting process sndC\n");

	sleepms(100);
	char buf[10] = "message 2";

	uint32 output = sendx(recvpid, buf, 10);
	printf("send C returned with out - %d\n", output);	
 }


void sndD(void) {
	printf("starting process sndD\n");

	sleepms(100);
	char buf[10] = "messge 3";

	uint32 output = sendx(recvpid, buf, 10);
	printf("send D returned with out - %d\n", output);	
 }