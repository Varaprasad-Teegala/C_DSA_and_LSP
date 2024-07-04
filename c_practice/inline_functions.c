#include <stdio.h>

static inline int func1(int x)
{
	int v;
	printf("hello\n");
	x = x*2;
	return x*x;
}

/*int func1(int x)
{
	printf("normal function : ");
	return x*x;
}*/

int main()
{
	int v = func1(4);
	printf("%c\n",v);
	printf("%d\n",func1(7));
}
