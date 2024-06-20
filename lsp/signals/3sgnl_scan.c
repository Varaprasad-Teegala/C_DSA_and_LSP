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

pthread_t t1,t2,t3;
char s[100];
char *p = s;
char *slave1 = "0x01";
char *slave2 = "0x02";
char *slave3 = "0x03";

void * lcd1()
{
	while(1)
	{
		printf("fun1\n");
		sleep(1);
	}
}

void * lcd2()
{
	while(1)
	{
		//signal(SIGINT,handler);
		printf("fun2\n");
                sleep(1);
	}
}

void * lcd3()
{
	while(1)
        {
                printf("fun3\n");
                sleep(1);
        }
}


void handler(int s)
{
	if( (strcmp(p,slave1)) == 0)
	{
		pthread_cancel(t2);
		pthread_cancel(t3);
	}
	else if (strcmp(p,slave2) == 0)
	{
		pthread_cancel(t1);
		pthread_cancel(t3);
	}
	else if(strcmp(p,slave3) == 0)
	{
		pthread_cancel(t1);
		pthread_cancel(t2);
	}
	else
		printf("Slave not available\n");
}

int main()
{
	signal(SIGINT,handler);

	pthread_create(&t1,NULL,lcd1,NULL);
	pthread_create(&t2,NULL,lcd2,NULL);
	pthread_create(&t3,NULL,lcd3,NULL);

	printf("Enter a any slave addr (0x01,0x02,0x02) : ");
	scanf("%[^\n]",s);

	raise(SIGINT);
	 
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	return 0;
}
