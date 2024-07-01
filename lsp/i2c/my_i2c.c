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

pthread_t t1,t2,t3,t4,t5;

int f1=0,f2=0,f3=0;
int shmid1;
char *p1;
char *slave1 = "0x01";
char *slave2 = "0x02";
char *slave3 = "0x03";

void handler1(int s)
{

}

void * motor()
{
	signal(SIGUSR1,handler1);
	while(1)
	{
		printf("fun1\n");
		sleep(1);
		if(f1 == 1)
			pause();
	}
}

void * temp()
{
	signal(SIGUSR1,handler1);
	while(1)
	{
		printf("fun2\n");
                sleep(1);
		if(f2 == 1)
			pause();
	}
}

void * lcd()
{
	signal(SIGUSR1,handler1);
	while(1)
        {
		//sem_wait(&s3);
                printf("fun3\n");
                sleep(1);
		if(f3 == 1)
			pause();
        }
}


void start_handler(int s)
{
	if( (strcmp(p1,slave1)) == 0)
	{
		f2 = 1;
		f3 = 1;
	}
	else if (strcmp(p1,slave2) == 0)
	{
		f1 = 1;
                f3 = 1;
	}
	else if(strcmp(p1,slave3) == 0)
	{
		f2 = 1;
                f1 = 1;
	}
	else if(strcmp(p1,"stop") == 0)
	{
		pthread_kill(t1,SIGUSR1);
		pthread_kill(t2,SIGUSR1);
		pthread_kill(t3,SIGUSR1);
		f1 = 0;
		f2 = 0;
		f3 = 0;
	}
	else
	{
		printf("Slave not available\n");
	}
}

void * send_data()
{
	signal(SIGTERM,start_handler);
	while(1)
	{
		scanf("%[^\n]",p1);
        	raise(SIGTERM);
        	getchar();
	}
}

int main()
{
	shmid1 = shmget(555,1024,0666 | IPC_CREAT);
        p1 = shmat(shmid1,NULL,0);	

	pthread_create(&t1,NULL,motor,NULL);
	pthread_create(&t2,NULL,temp,NULL);
	pthread_create(&t3,NULL,lcd,NULL);
	pthread_create(&t4,NULL,send_data,NULL);
 
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	return 0;
}

