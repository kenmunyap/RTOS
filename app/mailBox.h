typedef struct{
	int counter;
	int size;
	//LinkedList BlockedTcb;
}Semaphore;

typedef struct{
	Tcb *owner;
	int counter;
	LinkedList blockedTcb;
}Mutex;

typedef struct{
	int *buffer;
	int size;
	Semaphore slotsAvaiable;
	Semaphore slotsUsed;
	int writeIndex;
	int readIndex;
	Mutex mutexforBuffer;
}Mailbox;

void mainboxInit(Mailbox *mailbox, int size);
void mailboxSendMessage(Mailbox *mailbox,int message);
int mailboxGetMessage(Mailbox *mailbox);

// multiple producer
/*
 * decrease slotsAvailable ->void semaphoreDown(Semaphore *sem,int count); / || Up (||)
 * acquireMutex (&mutexForBuffer) ->to avoid 2 different data put into same slot //single no need
 * add data into the slot buffer
 * releaseMutex (&mutexForBuffer) //single no need
 * increase slotsUsed
 */

//consumer
/*
 * decrease slotsUsed
 * acquireMutex (&mutexForBuffer)
 * get the data from slot/buffer
 * releaseMutex(&mutexForBuffer)
 * increase slotsAvailable
 */
