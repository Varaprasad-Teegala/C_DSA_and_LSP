
//		SERVER		//

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

int ser_fd, clt_fd;
pthread_t t1,t2;
char s[1024];

void * tx()
{
	while(1)
	{
		scanf("%[^\n]",s);
		getchar();
		write(clt_fd,s,strlen(s));
		memset(s,'\0',1024);
	}
}

void * rx()
{
	while(1)
	{
		read(clt_fd,s,1024);
		printf("From Ramesh : %s\n",s);
		memset(s,'\0',1024);
	}
}

void handler(int s)
{
	close(ser_fd);
	close(clt_fd);
	kill(getpid(),SIGTERM);
}

int main()
{
	signal(SIGINT,handler);

	int ser_len, clt_len;
    	struct sockaddr_in ser_addr,clt_addr;

	/*  Create an unnamed socket for the server.  */
        ser_fd = socket(AF_INET, SOCK_STREAM, 0);

	/*  Name the socket.  */
    	ser_addr.sin_family = AF_INET;
    	ser_addr.sin_addr.s_addr = inet_addr("10.0.2.15");
    	ser_addr.sin_port = 9734;

	// assigning name/fd to socket
    	ser_len = sizeof(ser_addr);
    	bind(ser_fd, (struct sockaddr *) &ser_addr, ser_len);

	/*  Create a connection queue and wait for clients.  */
    	listen(ser_fd, 1);
	printf("Connecting......\n");
	/*  Accept a connection.  */
        clt_len = sizeof(clt_addr);
       	clt_fd = accept(ser_fd, (struct sockaddr *) &clt_addr, &clt_len);
	printf("Connected\n");

	pthread_create(&t1,NULL,tx,NULL);
	pthread_create(&t2,NULL,rx,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
