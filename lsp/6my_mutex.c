#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h> 
#include <semaphore.h>

void * fun1();
void * fun2();

pthread_mutex_t m,m1;

int main()
{
	pthread_t t1,t2;

	pthread_mutex_init(&m,NULL);

	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	pthread_mutex_destroy(&m);
}

void * fun1()
{
	int i=0;
	while(1)
	{
		pthread_mutex_lock(&m);
		printf("%d\n",i);
		i++;
		pthread_mutex_unlock(&m);
		usleep(500000);
	}
}


void * fun2()
{
	int i = 65;
	while(1)
	{
		pthread_mutex_lock(&m);
		printf("%c\n",i);
		i++;
		pthread_mutex_unlock(&m);
		usleep(500000);
	}
}
