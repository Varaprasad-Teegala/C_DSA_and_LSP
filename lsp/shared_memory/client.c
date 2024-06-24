
//                CLIENT

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

pthread_t t1,t2;
char *p1,*p2 ;
sem_t *s1,*s2,*s3,*s4;
int shmid1,shmid2;

void * tx()
{
	char tx_buff[1024];
        while(1)
        {
                sem_wait(s3);

                //printf("Me : ");
                scanf("%[^\n]",tx_buff);
                getchar();
                strcpy(p2,tx_buff);

                sem_post(s4);
        }

}

void * rx()
{
        char rx_buff[1024];
        while(1)
        {
		sem_wait(s2);

                strcpy(rx_buff,p1);
                printf("from ramesh : %s\n",rx_buff);
		memset(p1,'\0',sizeof(rx_buff));

		sem_post(s1);

        }
}

int main()
{
        shmid1 = shmget(555,1024,0666 | IPC_CREAT);
        p1 = shmat(shmid1,NULL,0);

	shmid2 = shmget(666,1024,0666 | IPC_CREAT);
        p2 = shmat(shmid2,NULL,0);

	s1 = sem_open("usr1",0);
	s2 = sem_open("usr2",0);
	s3 = sem_open("usr3",0);
        s4 = sem_open("usr4",0);

        int s1val,s2val,s3val,s4val;
        sem_getvalue (s1, &s1val);
        sem_getvalue (s2, &s2val);
	sem_getvalue (s3, &s3val);
        sem_getvalue (s4, &s4val);
        printf("shmid1:%d  shmid2:%d s1_id:%d    s2_id:%d     s3_id:%d   s4_id:%d\n",shmid1,shmid2,s1val,s2val,s3val,s4val);

        pthread_create(&t1,NULL,rx,NULL);
	pthread_create(&t2,NULL,tx,NULL);

	pthread_join(t1,NULL);
        pthread_join(t2,NULL);

        return 0;
}

