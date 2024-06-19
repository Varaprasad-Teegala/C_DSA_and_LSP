#include <stdio.h>
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
#include <unistd.h>
pthread_t t1,t2;
sem_t *s1,*s2;

int i=0;

void * even()
{
        while(1)
        {
                sem_wait(s1);
                printf("fun1 : %d\n",i);
		i++;
		sleep(1);
                sem_post(s2);
        }
}

void * odd()
{
        while(1)
        {
        	sem_wait(s2);
                printf("fun2 : %d\n",i);
		i++;
                sleep(1);
                sem_post(s1);
        }
}

int main()
{       
        s1 = sem_open("em1",O_CREAT,0666,1);
        s2 = sem_open("em2",O_CREAT,0666,0);

        pthread_create(&t1,NULL,even,NULL);
        pthread_create(&t2,NULL,odd,NULL);

        pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	return 0;
}
