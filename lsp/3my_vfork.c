#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int a = 12;
	int *p = &a;
	pid_t x;
	x = vfork();
	if(x == 0)  // child process
	{
		sleep(2);
		*p+=1;
		printf("\nthis is child process of pid: %d  parent process pid : %d\n",getpid(),getppid());
		printf("\n p : %d\n",*p);
		exit(0);
	}
	else 
	{
		waitpid(x,0,WNOHANG);
		printf("\nthis is parent process with pid : %d and chile process pid of : %d\n",getpid(),x);
		printf("\n p : %d\n",*p);
		int v = execl("/home/vara/personal_github/Mirafra/lsp/my_vfork",NULL,NULL);
	}

	printf("Ending......\n");
	return 0;
}
