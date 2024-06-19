
//      CLIENT

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ipc.h> 
#include <sys/msg.h>

struct mesg_buffer 
{
    long mesg_type;
    char mesg_text[BUFSIZ+1];
} message;

int main()
{       	
	 int msgid;
	 msgid = msgget(555, 0666 | IPC_CREAT);
	 msgrcv(msgid, &message, BUFSIZ, 1, 0);
	 printf("Data Received is : %s", message.mesg_text);
   	 msgctl(msgid, IPC_RMID, NULL);

    return 0;

}     
