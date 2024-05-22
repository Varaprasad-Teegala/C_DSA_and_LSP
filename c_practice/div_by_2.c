#include <stdio.h>

int main()
{
	int x;
	printf("Enter a number : ");
	scanf("%d",&x);
	if(x == 1)
		printf("%d is divisible by 2 ",x);
	else if (x & 1)
		printf("%d is not divisible by 2",x);
	else
		printf("%d is divisible by 2",x);
	return 0;
}
