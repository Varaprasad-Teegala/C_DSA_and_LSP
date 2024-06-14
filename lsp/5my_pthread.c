#include <pthread.h> 
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int x = 12;
int b =  0;
void *func1()
{
	while(1)
	{
		if(x == 13  && b == 0)
		{
			b=1;
			printf("1\n");
			pthread_exit("func1\n");
		}
		if(b == 1)
			break;
	}
	pthread_exit("func1\n");
}

void *func2(void *s)
{
	while(1)
	{
		if(x == 14 && b==0)
		{
			b = 1;
			printf("2\n");
			pthread_exit("Func2\n");
		}
		if(b == 1)
                        break;
	}
	pthread_exit("func2\n");
}

int main()
{
	pthread_t t1,t2;
	if(pthread_create(&t1,NULL,func1,NULL)==0)
		printf("thread1 formed\n");
	else
		printf("thread1 error\n");

	if(pthread_create(&t2,NULL,func2,"Hello")==0)
		printf("thread2 formed\n");
	else
		printf("thread2 error");
	while(1)
	{
		printf("enter a value : ");	
		scanf("%d",&x);
		if(b == 1)
			break;
	}
	pthread_join(t1,NULL);
        pthread_join(t2,NULL);
	return 0;
}
