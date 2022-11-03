#include <xinu.h>

void executedetour2(void)

{

  int flag = proctab[currpid].prmakedetour;


  if (flag==0)
  {
    return ;
  }
   proctab[currpid].prmakedetour=0;
  (*(proctab[currpid].prcbftn))();


// kprintf("exe2\n");


}