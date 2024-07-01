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
#include <sys/shm.h>

pthread_t p1,p2,p3;
void handler(int s);

void * motor()
{
	signal(SIGUSR1,handler);
	while(1)
	{
		printf("motor\n");
		sleep(1);
		pause();
		printf("hello \n hi \n bruh\n");

	}
}

void * temp()
{

}

void * lcd()
{
	
}

void handler(int s)
{

}

int main()
{
	//signal(SIGINT,handler);
        pthread_create(&p1,NULL,motor,NULL);
        sleep(3);
        //raise(SIGINT);
        //pthread_kill(p1,SIGUSR1);
        //sleep(3);
        //pthread_kill(p1,SIGINT);
        pthread_join(p1,NULL);
        return 0;

}
