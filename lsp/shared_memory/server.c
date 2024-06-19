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

void * txn()
{
	//while(1)
	//{
		int k = 555;
        	int id = shmget(k,1024,0666 | IPC_CREAT);
        	char *s = (char *)shmat(id,0,0);
        	//printf("Me : ");
        	//scanf("%[^\n]",s);
       	 	//shmdt(s);
	//}
}

void * rxn()
{
/*	//while(1)
       // {
                int k = 666;
                int id = shmget(k,1024,0666 | IPC_CREAT);
                char *s = (char *)shmat(id,0,0);
                printf("From Suresh : %s\n",s);
                shmdt(s);
                shmctl(id,IPC_RMID,NULL);
       // }*/
}


int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,txn,NULL);
	pthread_create(&t2,NULL,rxn,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
