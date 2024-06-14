#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h> 
#include <semaphore.h>


void * func1();
void * func2();

int i=0;
int j = 999;
sem_t s1,s2;

int main()
{

	pthread_t t1,t2;

	sem_init(&s1,0,0);
	sem_init(&s2,0,20);

	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);


	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	sem_destroy(&s1);
	sem_destroy(&s1);

}

void * func1()
{
	while(1)
	{
		sem_wait(&s2);
		i++;
		printf("---->  i: %d   s1 = %d   s2 = %d\n",i,s1,s2);
		if(i==20)
		getchar();
		//sleep(1);
		sem_post(&s1);
	}
}

void * func2()
{
	while(1)
	{	
		sem_wait(&s1);
		j--;
		printf("i: %d   s1 = %d   s2 = %d\n",i,s1,s2);
		//sleep(1);
		sem_post(&s2);
	}
}
