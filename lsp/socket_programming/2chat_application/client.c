
//	CLIENT		//

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
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int fd;
pthread_t t1,t2;
char s[1024];

void * tx()
{
	while(1)
        {
                scanf("%[^\n]",s);
                getchar();
                write(fd,s,strlen(s));
		memset(s,'\0',1024);
        }

}

void * rx()
{
	while(1)
        {
                read(fd,s,1024);
		if(s[0] != '\0')
		{
                	printf("From Suresh : %s\n",s);
			memset(s,'\0',1024);
		}
        }
}

void handler(int s)
{
	close(fd);
        kill(getpid(),SIGTERM);
}

int main()
{
	signal(SIGINT,handler);

    	int len;

    	struct sockaddr_in addr;
	/*  Create a socket for the client.  */
    	fd = socket(AF_INET, SOCK_STREAM, 0);

	/*  Name the socket, as agreed with the server.  */
    	addr.sin_family = AF_INET;
    	addr.sin_addr.s_addr = inet_addr("10.0.2.15");
    	addr.sin_port = 9734;
    	len = sizeof(addr);

	/*  Now connect our socket to the server's socket.  */
    	connect(fd, (struct sockaddr *) &addr, len);


	pthread_create(&t1,NULL,tx,NULL);
        pthread_create(&t2,NULL,rx,NULL);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
        return 0;
} 
