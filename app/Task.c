#include "Task.h"
#include "linkedList.h"

uint8_t taskOneStack[1028];


linkedList *readyQueue;
Tcb *runningTcb;
Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;

CpuContext *cc = (CpuContext *)((uint32_t)(&taskOneStack[1028]) - sizeof(CpuContext));


 void taskOne(void) {
 while(1);
}

/**
  brief Initialize all the Tcb
**/
void InitTcb(){
  mainTcb.name = "main thread";
  mainTcb.sp = 0x12;
  taskOneTcb.name = "thread #1";
  taskOneTcb.sp = (uint32_t)cc;

  cc->r4  = 0xaaaaaaa;
  cc->r5  = 0xbbbbbbb;
  cc->r6  = 0xccccccc;
  cc->r7  = 0xddddddd;
  cc->r8  = 0xeeeeeee;
  cc->r9  = 0xfffffff;
  cc->r10 = 0x1212122;
  cc->r11 = 0x1313131;
  cc->r0  = 0x1141411;
  cc->r1  = 0x1515115;
  cc->r2  = 0x1616161;
  cc->r3  = 0x1711717;
  cc->r12 = 0x1811818;
  cc->lr = 0x1000;
  cc->pc = (uint32_t)taskOne;
  cc->xpsr = 0x1200;

  runningTcb = &mainTcb;
  initLinkedList(&readyQueue);
  List_addLast(&readyQueue,&taskOneTcb);
}

