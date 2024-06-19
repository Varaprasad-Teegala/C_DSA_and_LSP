#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h> 
#include <semaphore.h>


int main()
{
	int fd[2];
	pipe(fd);
	int p;
	int x = fork();
	if(x == 0)  // child process
	{
		//while(1)
                //{
                        open(fd[1]);
                        char s[1000];
                        printf("Write server PID-%d : ",getpid());    //Write 
                        scanf("%[^\n]s",s);
                        write(fd[1],s,strlen(s));
                        close(fd[1]);
                //}

	}
	else if(x>0)  // parent process
	{	
		//while(1)
                //{
                        //open(fd[0]);
                        char c[BUFSIZ+1];
			//while(read(fd[0],c,BUFSIZ))
			//{	
				open(fd[0]);
                        	read(fd[0],c,BUFSIZ);
                        	printf("client PID-%d : %s\n",getpid(),c);   //read
				close(fd[0]);
			//}
                        //close(fd[0]);
               // }

	}
	else
	{
		perror("Error in creating fork\n");
	}
}
