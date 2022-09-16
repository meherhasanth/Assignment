#include <xinu.h>
#define STDERR (-1)


uint32 lifetime(uint32 pid)
{

    if (( ((pid) < 0) || \
			  ((pid) >= NPROC) || \
			  (proctab[(pid)].prstate == PR_FREE)))
    {
        return STDERR;
    }
    struct procent *prptr = &proctab[pid];
    kprintf("AAA %d %d\n", fineclkcounter, prptr->prbirthday);
    // kprintf("%d\n", prptr.prbirthday);
    return (fineclkcounter - prptr->prbirthday);
}
