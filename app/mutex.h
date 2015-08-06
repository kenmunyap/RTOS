#ifndef MUTEX_H
#define MUTEX_H

#include <stdint.h>
#include "Task.h"

//Task Control Block
typedef struct{
    Tcb *owner;
    int counter;
    LinkedList blockedTcb;
}Mutex;


void mutexInit(Mutex *mutex);
void mutexAcquire(Mutex *mutex);
void mutexRelease(Mutex *mutex);

#endif // MUTEX_H