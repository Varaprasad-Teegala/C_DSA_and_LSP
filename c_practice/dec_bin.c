#include <stdio.h>

int main()
{
	char c[1000];
	int x;
	scanf("%d",&x);
	for(int i=0;i<32;i++)
	{
		c[i] = ((x & (1 << 31-i))>>(31-i))+48;
		c[i+1] = '\0';	
	}
	printf("bin : %s\n",c);
	return 0;
}
