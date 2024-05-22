#include <stdio.h>
int main()
{
	int x;
	printf("Enter a number :");
	scanf("%d",&x);
	if (x & 1)
		printf("ODD\n");
	else
		printf("EVEN\n");
	return 0;
}
