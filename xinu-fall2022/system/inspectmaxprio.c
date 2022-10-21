
#include <xinu.h>

// extern struct mfeedbqx dynqueue[];


pri16 inspectmaxprio(void)
{
int i;


for (i=9;i>=0;i--)
{   

    if (dynqueue[i].count==0)
    {
        continue;
    }

    return i;
    
}
return SYSERR;




}