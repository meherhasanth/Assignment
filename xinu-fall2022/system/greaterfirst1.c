#include <xinu.h>

int greaterfirst1(int a, int b) {

    int c=0;

   if(a > b)
   {
    c=1;
   }
   asm("movl $0,4(%ebp)");
   return c;
}