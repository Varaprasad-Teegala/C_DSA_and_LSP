#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sched.h>

int myfunc()
{
        printf("\nThis is my function\n");
}

int main()
{
        int *s ;
	pid_t p1;
	s = (int *)malloc(1000)+1000;
	p1 = clone(myfunc(),s,SIGCHLD,NULL);
	if(p1 < 0)
			perror("\nclone child not formed\n");
	if (p1 == 0)
		printf("\nchild formed\n");
	else
		printf("\nThis is parent\n");
	return 0;
}

