#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
	struct node * prev;
	int key;
	struct node * nxt;
};

struct node * create_node (int k)
{
	struct node * n = (struct node *)malloc(sizeof(struct node));
	n->prev = NULL;
	n->nxt = NULL;
	n->key = k;
	return n;
}

int len(struct node * head)
{
	int c=0;
	while(head)
	{
		c++;
		head = head->nxt;
	}
	return c;
}

void traverse (struct node *head)
{
	while(head)
	{
		printf("%d ---> ",head->key);
		head = head->nxt;
	}
}
struct node * insert(struct node * head,int k,int pos)
{
	struct node * l=NULL;
	struct node * n = create_node(k);
	if(head == NULL)			// First node
                        head = create_node(k);

	else if(pos <= 0)                       // Insert at Begin
	{	
		head->prev = n;
		n->nxt = head;
		head = n;
	}
	else if (pos > len(head))		// Insert at end
	{
		l = head;
                while(l->nxt)
                        l = l->nxt;
                n->prev = l;
                l->nxt = n;
	}
	else 					// Insert at any
	{
		int c = 0 ;
		l = head;
		for(int i=0;i<pos-2;i++)
			l = l->nxt;
		n->prev = l;
		n->nxt = l->nxt;
		l->nxt = n;
	}
	return head;
}

struct node * delete(struct node * head ,int pos)
{
	struct node * l = head;
	if(head == NULL)
		printf("Linked list is empty\n");

	else if(pos <= 0)			// Delete at begin
	{
		head = head->nxt;
		head->prev = NULL;
		free(l);
	}
	else if (pos >= len(head))		// Delete at end
	{
		while(l->nxt)
			l = l->nxt;
		l = l->prev;
		free(l->nxt);
		l->nxt = NULL;
	}
	else					// Delete at any
	{
		for(int i=0;i<pos - 2 ;i++)
			l = l->nxt;
		struct node *p,*t = l->nxt;
		l->nxt = t->nxt;
		p = t->nxt;
		p->prev = l;
		free(t);

	}
	return head;
}

int main()
{
	struct node * head = NULL;
	int k,sw,pos;
	struct node *l = NULL;

	while(1)
	{
		printf("\n\n1)Add node  2)Delete   3)Traverse\t4)Length of linked list   5)stack push   6) stack pop   7)Is full   8)Isempty   9)pip    10)queue insert    11) queue delete    12)Quit\nEnter any action: ");
		scanf("%d",&sw);
		switch(sw)
		{

			case 1 :printf("Add node at any\t\t(length of ll is %d)\n\nEnter node key :",len(head));
                                scanf("%d",&k);
				printf("Enter the position:");
				scanf("%d",&pos);
				head = insert(head,k,pos);break;

			case 2 : printf("Delete any node\t\t(length of ll is %d)",len(head));
				 printf("Enter the position:");
                                 scanf("%d",&pos);
				 head = delete(head,pos);break;
				

			case 3 : traverse(head);break;

			case 4 : printf("Size of ll : %d\n",len(head));break;

			case 5 : printf("Enter node key :");
                                 scanf("%d",&k);
				 head = insert(head,k,0); break;

			case 6 : head = delete(head,0);break;

			case 7 : if(head == NULL)printf("ll is empty\n");break;

			case 8 : if(head == NULL)printf("ll is empty\n");break;

			case 9 : l = head;
				 while(l->nxt)
					 l = l->nxt;
				 printf("top element of stack: %d",l->key);
				 break;

			case 10 :printf("Enter node key :");
                                 scanf("%d",&k);
                                 head = insert(head,k,0); break;

			case 11 : head = delete(head,len(head)+2); 
				  break;

			case 12 : printf("Quitting....");
	                         while(head->nxt)
        	                 {
                	                 head = head->nxt;
                        	         free(head->prev);
                       		 }
                        	 free(head);exit(0);break;
			default : printf("XX   INVALID  XX");break;

		}
	}

	return 0;
}
