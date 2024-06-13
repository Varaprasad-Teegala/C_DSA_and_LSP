#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>



int main()
{
	if(execl("/home/vara/personal_github/Mirafra/lsp/my_vfork",NULL,NULL))
		printf("\nIts came ....\n");
	else
		perror("\nError occured\n");	
	return 0;
}
