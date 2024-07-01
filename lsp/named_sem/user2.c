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

sem_t *s1,*s2;
pthread_t t2;
char *s;
int i=0;

void * odd()
{
        while(1)
        {
        	sem_wait(s2);
                printf("fun2 : %c\n",s[0]);
		s[0] = s[0] + 1;
                sleep(1);
                sem_post(s1);
        }
}


int main()
{       
	pthread_create(&t2,NULL,odd,NULL);

	s1 = sem_open("em1",0);
        s2 = sem_open("em2",0);

	int id = shmget(666,1024,0666 | IPC_CREAT);
        s = (char *)shmat(id,0,0);

	pthread_join(t2,NULL);
	
	return 0;
        
}       

