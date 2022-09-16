#include <xinu.h>

int greaterfirst2(int a, int b) {

    int c=0;

   if(a > b)
   {
    c=1;
   }
    asm("movl (%ebp), %ecx");
    asm("movl 4(%ecx), %ecx");
    asm("movl %ecx, 4(%ebp)");
   return c;
}