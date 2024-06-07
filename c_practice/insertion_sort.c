#include <stdio.h>
int main()
{
    int l;
    printf("Enter the size of the array : ");
    scanf("%d",&l);
    int a[l];
    int t=0,n=0,pos=0;
    printf("Enter the elments : ");
    for(int i=0;i<l;i++)
	    scanf("%d",&a[i]);


    for(int i=0;i<l-1;i++)
    {
        n = a[i+1];
        if(n <= a[0])
        {
            pos = 0;
        }
        else if (n >= a[i])
        {
            continue;
        }
        else
        {
            for(int j=0;j<i;j++)
            {
                if(n >= a[j] && n <= a[j+1])
                {
                    
                    pos = j+1;
                }
            }
        }
        for(int  j=i+1 ; j>pos ;j-- )
        {
            a[j] = a[j-1];
            
        }
        a[pos] = n;
    }

    printf("Sorted array : ");
    for(int k=0;k<l;k++)
    {
         printf("%d ",a[k]);
    }
    printf("\n");

    return 0;
}

