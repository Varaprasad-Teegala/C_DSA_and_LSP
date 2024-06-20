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

void  fun(int signum)
{
	printf("this is handler signal number : %d of pid : %d\n",signum,getpid());
	printf("Exiting the process due to SIGINT.......\n");
	kill(getpid(),SIGKILL);    //SIGTERM,

}

int main()
{
	signal(SIGINT,fun);
	signal(SIGALRM,fun);
	//signal(SIGCHLD,handler3);
	int i=0;
	alarm(5);
	raise(SIGINT);
	//fork();
	while(1)
	{
		printf("i : %d\n",i++);
		sleep(1);
	}
	return 0;

}
