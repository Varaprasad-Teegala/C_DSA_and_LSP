#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h> 
#include <semaphore.h>


sem_t  s1,s2;
int i=0;
void * fun1()
{
	while(1)
	{
		sem_wait(&s1);
		
		printf("Even : %d\n",i);
		i++;
		sleep(1);
		
		sem_post(&s2);
	}
}

void * fun2()
{
	while(1)
	{
		sem_wait(&s2);
               
                printf("Odd : %d\n",i);
                i++;
		sleep(1); 

                sem_post(&s1);
	}
}

int main()
{
	sem_init(&s1,0,1);
        sem_init(&s2,0,0);

	pthread_t t1,t2;
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);

	pthread_join(t1,NULL);	
	pthread_join(t2,NULL);
	sem_destroy(&s1);
	sem_destroy(&s2);
}
