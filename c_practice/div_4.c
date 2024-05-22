#include <stdio.h>
#include <stdlib.h>
int main()
{
        int x,t;
        printf("Enter a number : ");
        scanf("%d",&x);
        t = x;
        if (x == 1)
        {
                printf("%d is power of 4\n",t);
                exit(0);
        }

	if (~(x & (3 << 0)))
	{
        	for(int i=0;i<32;i++)
        	{
                	if(x & (1 << i))
                	{
                        	x = x & ~(1 << i);
                        	if(x)
                        	{
                        	        printf("%d is not power of 4\n",t);
                               		 break;
                        	}
                       		else
                                	printf("%d is power of 4\n",t);
                	}
		}	
        }
	else
		printf("%d is divisible by 4\n",t);
        return 0;
}

