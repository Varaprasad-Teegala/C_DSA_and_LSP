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
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
	struct stat x;
	int fd = open("text.txt",O_RDONLY);
	fstat(fd,&x);
	printf("Size of the file : %ld\n",x.st_size);
	printf("blocks of the file : %ld\n",x.st_blocks);

	char * map = mmap(NULL,x.st_size, PROT_READ|PROT_WRITE ,MAP_PRIVATE,fd,0);
	close(fd);

	char s[1000] = "apple ball cat dog elephant\nfish goat";
	write(1,map,x.st_size);

	read(0,map,x.st_size);
	printf("\n\n\n");
	write(1,map,x.st_size);

	munmap(map,x.st_size);
	return 0;
}
