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
#include <sys/time.h>

int f,fd0,fd1,fd2,fd3;
char *s1,*s2,*s3,*s4;
fd_set fdts;
struct timeval tv;
int w,x,y,z;
int sel;
pthread_t t1;

void* selectt()
{
	while(1)
	{
	/*fd0 = 0;
        fd1 = open("text1.txt",O_RDWR);
        fd2 = open("text2.txt",O_RDWR);
        fd3 = open("text3.txt",O_RDWR);

	FD_ZERO(&fdts);

	FD_SET(fd0,&fdts);
	FD_SET(fd1,&fdts);
	FD_SET(fd2,&fdts);
	FD_SET(fd3,&fdts);

	tv.tv_sec = 5;
	tv.tv_usec = 0;*/
	sel = select(fd3+1,&fdts,NULL,NULL,&tv);
	if(sel)
	{
		if(FD_ISSET(fd0,&fdts))
		{
			/*int f = open("text4.txt", O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR);
			lseek(f,0,SEEK_SET);
			write(f,s4,strlen(s4));
			
			lseek(f,0,SEEK_SET);*/
		
			printf("Text.4 is :\n");
			char x[56];
			read(f,x,strlen(s4));
			write(1,x,strlen(s4));
			lseek(f,0,SEEK_SET);
			close(f);
			printf("\n---------------------------------------------------------------\n");
		}
	
		if(FD_ISSET(fd1,&fdts))
        	{
        	        /*printf("Befor editing text1.txt : \n");
        	        char x1[100];
        	        read(fd1,x1,30);
        	        x1[27] = '\0';
        	        write(1,x1,30);
	
	                lseek(fd1,0,SEEK_SET);*/

	                printf("After editing text1.txt : \n");
	                write(fd1,s1,strlen(s1));

	                lseek(fd1,0,SEEK_SET);

        	        char x[strlen(s1)];
            	   	read(fd1,x,sizeof(x));
              	        x[strlen(s1)] = '\0';
         	        write(1,x,sizeof(x));
			close(fd1);
                	printf("\n---------------------------------------------------------------\n");
        	}

		if(FD_ISSET(fd2,&fdts))
        	{
			/*printf("Befor editing text2.txt : \n");
			char x1[1000];
                	read(fd2,x1,30);
                	write(1,x1,30);
               
			lseek(fd2,0,SEEK_SET);*/
	
			printf("\nAfter editing text2.txt\n");
			write(fd2,s2,strlen(s2));

			lseek(fd2,0,SEEK_SET);

                	char x[strlen(s2)+1];
                	read(fd2,x,strlen(s2));
                	write(1,x,strlen(s2));
			close(fd2);
			printf("\n---------------------------------------------------------------\n");
		}
	
		if(FD_ISSET(fd3,&fdts))
      		{
			printf("Befor editing text3.txt : \n");
			char x1[1000];
                	read(fd3,x1,27);
                	write(1,x1,27);
	
			lseek(fd3,0,SEEK_SET);

        	        printf("Afteer editing text3.txt : \n");
        	        write(fd3,s3,strlen(s3));

			lseek(fd3,0,SEEK_SET);

                	char x[strlen(s3)+1];
                	read(fd3,x,strlen(s3));
                	write(1,x,strlen(s3));
			close(fd3);
                	printf("\n---------------------------------------------------------------\n");
		}
	}
	else
	{
		printf("Timed out.......\n");
		close(fd1);
		close(fd3);
		close(fd2);
	}
}
}	

int main()
{
	pthread_create(&t1,NULL,selectt,NULL);

	s1 = "ferrari maruthi mazda dodge honda suzuki\n";
	s2 = "cucumber radish ladiesfingure lettice cabbage\n";
	s3 = "shirt pant jacket raincoat shoes watch\n";
	s4 = "c java python fortran c++ javascript machinelearning\n";	

	fd0 = 0;
        fd1 = open("text1.txt",O_RDWR);
        fd2 = open("text2.txt",O_RDWR);
        fd3 = open("text3.txt",O_RDWR);

        FD_ZERO(&fdts);

        FD_SET(fd0,&fdts);
        FD_SET(fd1,&fdts);
        FD_SET(fd2,&fdts);
        FD_SET(fd3,&fdts);

        tv.tv_sec = 5;
        tv.tv_usec = 0;

	// Creating file4.txt
	f = open("text4.txt", O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR);
        lseek(f,0,SEEK_SET);
        write(f,s4,strlen(s4));
        lseek(f,0,SEEK_SET);

	// Editing file1.txt
	printf("Befor editing text1.txt : \n");
        char x1[100];
        read(fd1,x1,30);
        x1[27] = '\0';
        write(1,x1,30);
        lseek(fd1,0,SEEK_SET);

	// Editing file2.txt
	printf("Befor editing text2.txt : \n");
        char x2[1000];
        read(fd2,x2,30);
        write(1,x2,30);
        lseek(fd2,0,SEEK_SET);
	
	// Editing file3.txt
	printf("Befor editing text3.txt : \n");
        char x3[1000];
        read(fd3,x3,27);
        write(1,x3,27);
        lseek(fd3,0,SEEK_SET);

	pthread_join(t1,NULL);
}
