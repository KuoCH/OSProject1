#include "syscall.h" 
int main()
{
  int j, k, r, l;
  Print( "The return value of OSAdd(15, 10) is " , 37); 
  j = OSAdd(15,10);
  PrintInt(j);
  Print( "\nThe return value of OSSub(" , 27); 
  PrintInt(j);
  Print( ", 15) is " , 9); 
  k = OSSub(j,15);
  PrintInt(k);
  Print( "\nThe return value of OSDiv(140, " , 32); 
  PrintInt(k);
  Print( ") is " , 5); 
  r = OSDiv(140,k);
  PrintInt(r);
  Print( "\nThe return value of OSMul(112, " , 32); 
  PrintInt(r);
  Print( ") is " , 5); 
  l = OSMul(112,r);
  PrintInt(l);
  Print( "\nHello, we are b98901008 & b98901020.\n" , 38); 
  Halt();
}
