#include <stdio.h>
int main()
{
	int a[]= {0,9,8,5,4,3,2,1};
	int l = sizeof(a)/4;
	int s,t;
	s = a[0];
	for(int i=0;i<l;i++)
	{
		if (s > a[i])
		{
			s = a[i];
			t = i;
		}
	}

	printf("smallest index : %d \nsmallest element : %d\n ",t,s);
	return 0;

}
