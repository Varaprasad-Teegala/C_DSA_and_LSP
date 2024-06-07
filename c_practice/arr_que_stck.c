#include <stdio.h>

/*void pop(int *a,int l)
{

}

void push(int *a,int l)
{

}*/
static int t1 = -1,t2 = -1;
void print(int *a,int *b)
{
	printf("t1 : %d   t2 : %d\n",t1,t2);
	printf("Queue : ");
	if(t1 == -1 && t2 == -1)
	{
		printf("No elements to remove\n");
		return;
	}
	for(int i=0;i<=t1;i++)
		printf("%d ----> ",a[i]);
	for(int i=0;i<=t2;i++)
		printf("%d ----> ",b[i]);
	printf("\n");
}

int enqueue(int *a,int *b,int n,int c)
{
	int x;
	if(t1 < n-1 && t2 == -1)
	{
		t1++;
		a[t1] = c;
		return -1;
	}
	else if(t2 < n-1)
	{
		for(;t2<n-1;t2++,t1--)
			b[t2+1] = a[t1];
		t1++;
		a[t1] = c;
		x = b[t2];
		t2--;
		return x;	
	}
	else
	{
		a[t1+1] = c;
		t1++;
		x = t2;
		t2--;
		return x;
	}
}

int dequeue(int *a,int *b,int l)
{
	int x;
	if(t2 != -1)
	{
		x = b[t2];
		t2--;
		return x;
	}
	else if(t1 != -1)
	{
		x = a[t1];
		t1--;
		return x;
	}
	else
	{	
		printf("No elements to remove \n");
		return -1;
	}
}

int main()
{
	int n;
//	printf("Size of queue : ");
//	scanf("%d",&n);
	int a[5];
	int b[5];
	enqueue(a,b,5,22);
	enqueue(a,b,5,33);
	enqueue(a,b,5,44);
	enqueue(a,b,5,55);
	enqueue(a,b,5,66);
	enqueue(a,b,5,77);
	enqueue(a,b,5,88);
	enqueue(a,b,5,99);
	print(a,b);
	dequeue(a,b,5);
	dequeue(a,b,5);
	dequeue(a,b,5);
	dequeue(a,b,5);
	dequeue(a,b,5);
//	enqueue(a,b,5,77);
	print(a,b);
	/*
	while(1)
	{
		char z;
		int c;
		int t;
		printf("1)Enque\n2)Dequeue\n3)Exit 4)print queue \nEnter a choice : ");
		getchar();
		scanf("%c",&z);
		switch(sw)
		{
			case '1' :printf("Enter element : ");
                		  scanf("%d",&c);
				  t =  enqueue(a,b,n,c);
				  if(t == -1)
					  printf("Queue not full....\n");
				  else
				  	printf("Removed element : %d\n",t);
				  break;

			case '2' :printf("Removed element : %d\n",dequeue(a,b,n));
				  break;


			case '3' :printf("Exit pgrm......\n");
				  exit(0);

			case '4' : print(a,b);
				   break;

			default  : printf("Invalid....\n");
		}
	}*/
	return 0;
}
