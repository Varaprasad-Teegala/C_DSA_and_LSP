#include <sys/time.h>
#include <sys/types.h>
#include<stdio.h>
#include <unistd.h>

int main() 
{
	fd_set rd;
	struct timeval tv;
	int err;
	FD_ZERO( & rd);
	FD_SET(0, & rd);
	tv.tv_sec=4;
	tv.tv_usec=0;
	err=select(1, & rd, NULL, NULL, & tv);
	if (err==0) //Timeout
	{
		printf("select timeout!!! :  %d \n",err);
	}
       	else if (err == -1) //Fail
	{
		printf("failure to select : %d\n",err);
	}
       	else // Success
	{
		printf("data avalible : %d\n",err);
	}
	return 0;
}
