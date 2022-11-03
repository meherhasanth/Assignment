#include <xinu.h>

void executedetour(void)

{

  int flag = proctab[currpid].prmakedetour;


  if (flag==0)
  {
    return;
  }
  proctab[currpid].prmakedetour=0;
  uint32 callback = (uint32) proctab[currpid].prcbftn;
  uint32 restore = (uint32) restoreregs;
  asm("pushl -12(%ebp)");
  asm("pushl $0x00000200");
  asm("pushl %cs");
  asm("pushl -8(%ebp)");
  asm("iret");

}