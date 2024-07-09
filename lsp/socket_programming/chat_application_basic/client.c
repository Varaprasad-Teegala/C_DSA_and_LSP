//              CLIENT                  //


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

int clt_fd;
pthread_t t1,t2;
char s[1024];

void handler(int s)
{
        close(clt_fd);
        kill(getpid(),SIGTERM);
}

void * tx()
{
        while(1)
        {
                scanf("%[^\n]",s);
                getchar();
                write(clt_fd , s, strlen(s));
        }
}

void * rx()
{
        while(1)
        {
                read(clt_fd , s , 1024);
                printf("%s\n",s);
        }
}


int main()
{
	signal(SIGINT,handler);

	struct sockaddr_un clt_addr;
	int clt_len;

	// Creating a socket
	clt_fd = socket(AF_LOCAL, SOCK_STREAM, 0);

	// naming newly created socket
	clt_addr.sun_family = AF_LOCAL;
	strcpy(clt_addr.sun_path,"my_socket");
	clt_len = sizeof(clt_addr);

	// Connecting to the socket
	connect(clt_fd, (struct sockaddr *) &clt_addr, clt_len);
	pthread_create(&t1,NULL,tx,NULL);
        pthread_create(&t2,NULL,rx,NULL);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
	return 0;
}
