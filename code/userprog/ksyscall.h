/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"
//#include "console.h"




void SysHalt()
{
  kernel->interrupt->Halt();
}


int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysPrint(char *input, int length){

  int data[1];

  for(int i=0;i<=length;i++){
    kernel->machine->ReadMem((int)input+i, 1, data);
    kernel->synchConsoleOut->PutChar(data[0]);
  }
  return 0;
}

int SysPrintInt(int op){
  int length=0;
  bool neg=false;
  int tmp=op;
  if(tmp<0){
    neg=true;
    tmp*=-1;
  }
  while(tmp>9){
    length++;
    tmp/=10;
  }
  char out[length+neg];
  if(neg) out[0]='-';
  if(neg) tmp=-op; else tmp=op;
  for(int iter=length+neg;iter>=neg;iter--){
    out[iter]=tmp%10+48;
    tmp/=10;
  }
  for(int i=0;i<=length+neg;i++){
    kernel->synchConsoleOut->PutChar(out[i]);
  }
  return 0;
}

int SysOSAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysOSSub(int op1, int op2)
{
  return op1 - op2;
}

int SysOSDiv(int op1, int op2)
{
  return op1 / op2;
}

int SysOSMul(int op1, int op2)
{
  return op1 * op2;
}
#endif /* ! __USERPROG_KSYSCALL_H__ */
