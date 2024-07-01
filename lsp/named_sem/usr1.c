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
pthread_t t1;
char *s;
int i=0;

void * even()
{
        while(1)
        {
                sem_wait(s1);
                printf("fun1 : %c\n",s[0]);
		s[0] = s[0] + 1;
		sleep(1);
                sem_post(s2);
        }
}

int main()
{
	s1 = sem_open("em1",O_CREAT,0666,1);
        s2 = sem_open("em2",O_CREAT,0666,0);

	int id = shmget(666,1024,0666 | IPC_CREAT);
        s = (char *)shmat(id,0,0);
	strcpy(s,"A");
        pthread_create(&t1,NULL,even,NULL);

        pthread_join(t1,NULL);
	
	return 0;

}
