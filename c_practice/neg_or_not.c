#include <stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	if(x & (1 << 31))
		printf("-ve\n");
	else
		printf("+ve\n");
	return 0;
}
