#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h> 
#include <semaphore.h>
sem_t s1,s2;
pthread_t p1,p2;
int stock[10];
int i1 = 10;
int i2 = 0;
void print()
{
	for(int i=0;i<10;i++)
		printf("%d ",stock[i]);
}
void * producer()
{
	while(1)
	{
		sem_wait(&s1);		
		stock[i1-1] = i1;
		print();
		int a ;
		sem_getvalue(&s1,&a);
		printf("                s1 : %d  i1 = %d\n",a,i1);
		i1--;
	}
}
void * consumer()
{
	while(1)
	{
		sem_post(&s1);
        	stock[i2] = 0;	
		print();
		int b ;
		sem_getvalue(&s1,&b),
                printf("                s1 : %d  i2 = %d\n",b,i2);
		i2++;
		if(i2 == 10)
			exit(0);
	}
}
int main()
{
	memset(stock,0,10);
	printf("Initially stock is : ");
	print();
	printf("\n");
	sem_init(&s1,0,10);
	sem_init(&s2,0,0);
	pthread_create(&p1,NULL,producer,NULL);
	pthread_create(&p2,NULL,consumer,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}
