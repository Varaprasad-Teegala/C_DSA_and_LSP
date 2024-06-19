
// 	SERVER

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
    char mesg_text[1000]; 
} message; 

int main()
{
    	 int msgid;
   	 msgid = msgget(555, 0666 | IPC_CREAT);
   	 message.mesg_type = 1;
   	 printf("ramesh : ");
   	 fgets(message.mesg_text,1000,stdin);
   	 msgsnd(msgid, &message, sizeof(message), 0);
}
