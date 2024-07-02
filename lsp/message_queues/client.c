
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

pthread_t t1,t2;
int msgid1,msgid2;

void handler (int s)
{
        printf("\ndeleting message queues.....\n");
        msgctl(msgid1,IPC_RMID,NULL);
        msgctl(msgid2,IPC_RMID,NULL);
        exit(0);
}

struct mesg_buffer 
{
    long mesg_type;
    char mesg_text[1024];
};
struct mesg_buffer send,rcv;

void * tx()
{
        while(1)
        {
                fgets(send.mesg_text,1024,stdin);
                msgsnd(msgid2, &send, sizeof(send), 0);
        }
}

void * rx()
{
        while(1)
        {
		msgrcv(msgid1, &rcv, BUFSIZ, 1, 0);
         	printf("%s\n",rcv.mesg_text);
        }
}


int main()
{
	signal(SIGINT,handler);

	pthread_create(&t1,NULL,tx,NULL);
        pthread_create(&t2,NULL,rx,NULL);
	 
	msgid1 = msgget(555, 0666 | IPC_CREAT);
	msgid2 = msgget(777, 0666 | IPC_CREAT); 
	send.mesg_type = 1;
   
	pthread_join(t1,NULL);
        pthread_join(t2,NULL);

    	return 0;

}     
