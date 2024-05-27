#include <stdio.h>
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	int l = 9; 
	int left = 0;
	int right = l-1;
	int n = 9;
	int m = (left+right)/2;
	while(1)
	{
		if (a[left] == n)
                {
                        printf("pos : %d",left);
                        break;
                }
                else if(a[right] == n)
                {
                        printf("pos : %d",right);
                        break;
                }

		else if(a[m] < n)
		{
			left = m;
			m = (left + right)/2;		
		}
		else if (a[m] > n)
		{
			right = m;
			m = (left+right)/2;
		}

		else
		{
			printf("pos : %d",m);
			break;
		}

	}

}
