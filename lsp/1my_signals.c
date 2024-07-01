#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void sgnl(int s)
{
	printf("\nTerminated....\n");
	exit(0);
}

int main()
{
	signal(SIGINT,sgnl);
	while(1)
	{
		sleep(1);
		printf("heiii\n");
	}
	return 0;
}
