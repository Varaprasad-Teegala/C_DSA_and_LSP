#include <stdio.h>
int main()
{
	int a[]= {-12,-31,-1,9,5,0,0,9,1,3,0,9,4,3,6,-23,0,1,56};
        int n = sizeof(a)/4;
	int s,t;
	for(int i=0;i<n-1;i++)
	{	
		s = a[i+1];
	 	for(int j=i+1;j<n;j++)
		{
			if(s > a[j])
			{
				s = a[j];
				t = j;
			}
		}
		if(s < a[i])
		{
			a[t] = a[i];
			a[i] = s;
		}
	}

	for(int i=0;i<n;i++)
                printf("%d ",a[i]);
	return 0;
}
