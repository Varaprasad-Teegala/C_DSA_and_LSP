#include <stdio.h>
#include <math.h>
#include <string.h>
int powe(int n,int l)
{
	int x = 1;
	for(int i=0;i<l;i++)
		x = x * n;
	return x;
}

int main()
{
	char c[1000];
	scanf("%[^\n]",c);
	int x=0;
	int l = strlen(c);
	for(int i=0;i<l;i++)
	{
		if(c[-i+l-1] == '1')
		{
			x = x + powe(2,i);
		}	      
	}
	printf("bin = %s  l = %d  res : %d\n",c,l,x);
	
	return 0;
}
