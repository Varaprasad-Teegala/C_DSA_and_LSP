#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node 
{
	int k;
	struct node *nxt;
};
int n;
int len(struct node * head)
{
	int l=0;
	while(head)
	{
		head = head->nxt;
		l++;
	}
	return l;
}

struct node * create_node(int key)
{
	struct node *n;
	n = (struct node *) malloc (sizeof(struct node));
	n->k = key;
	n->nxt = NULL;
	return n;
}

void traverse(struct node * head)
{
	while(head)
	{
		printf("%d--->",head->k);
		head = head->nxt;
	}
	printf("\n");
}

struct node* insert(struct node *h,int pos)
{
	int m;
	printf("Enter new node key : ");
	scanf("%d",&m);
	struct node * l = create_node(m);
	if(pos == 1)
	{
		l->nxt = h;
		h = l;
	}

	else if(pos == len(h))
	{
		struct node* k = h;
		while(k->nxt)
			k = k->nxt;
		k->nxt = l;
	}
	else if(pos>len(h))
	{
		printf("Out of bounds\n");
	}	
	else
	{	struct node *k=h;
		for(int i=0;i<pos-2;i++)
			k = k->nxt;
		l->nxt = k->nxt;
		k->nxt = l;
	}
	return h;
}

struct node * delete(struct node* head,int pos)
{
	struct node * l = head;
	if(pos == 1 )
		head = head->nxt;	

	else if(pos == len(head))
	{
		for(int i=0;i<len(head)-2;i++)
			l = l->nxt;
		l->nxt = NULL;
	}

	else if(pos > len(head))
	{
		printf("Out of bounds\n");
	}

	else
	{
		for(int i=0;i<pos-2;i++)
                        l = l->nxt;
		l->nxt =l->nxt->nxt;

	}
	return head;

}

int main()
{
	struct node * head = NULL;
	struct node *l = NULL;
	int m;
	printf("Enter number of nodes :");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter key of node - %d : ",i+1);
		scanf("%d",&m);
		if(head == NULL)
		{
			head  = create_node(m);
			l = head;
		}
		else
		{
			l->nxt = create_node(m);
			l = l->nxt;
		}
	}
	printf("\n");
	traverse(head);
	head = insert(head,5);
	traverse(head);
	head = insert(head,1);
        traverse(head);
	head = insert(head,3);
        traverse(head);

	printf("len : %d\n",len(head));
	printf("Delete at begin:\n");
	head = delete(head,1);
        traverse(head);
	printf("Delete at any:\n");
	 head = delete(head,6);
        traverse(head);
	printf("Delete at end:\n");
	head = delete(head,len(head));
        traverse(head);




	return 0;
}
