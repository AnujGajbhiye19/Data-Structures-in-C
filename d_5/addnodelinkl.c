#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* start;
int n;

void create_linkedl()
{
	printf("Enter no.of nodes to create Linked List: ");
	scanf("%d",&n);										//no. of nodes
	struct node* lnode;									//ptr to current last node
	struct node* new = malloc(sizeof(struct node));
	printf("Enter data for 1st node: ");
	scanf("%d",&new->data);
	new->next=NULL;

	//now, There is only one node in linked list. Hence, first=last=new
	start = new;
	lnode = new;

	//Now take input for remaining nodes
	for(int i=1;i<n;i++)
	{
		new = malloc(sizeof(struct node));
		printf("Enter data for Next Node: ");
		scanf("%d",&new->data);
		new->next=NULL;
		//Now assign address of new node to previous node (ie.lastnode)
		lnode->next=new;
		//now change the pointer lastnode to actual lastnode
		lnode=new;
	}// loop will run untill the no.of nodes becomes value of n;
}

void add_node()
{
	struct node* newn= malloc(sizeof(struct node));
	printf("Enter the position at where you want to add a node(Consider 0 INDEXING): ");
	int n;
	scanf("%d",&n);
	printf("Enter data to add on the node: ");
	scanf("%d",&newn->data);
	struct node* prev;
	struct node* cur;
	cur=start;
	for(int i=1;i<=n;i++)
	{
		prev=cur;
		cur=cur->next;
	}
	prev->next=newn;
	newn->next=cur;
}

void printl()
{
	//create a pointer which is going to travel node->to->node
	struct node* ptr;
	ptr=start;
	printf("\nLinked List:- Start->");
	while(ptr!=NULL)
	{
		printf(" %d ",ptr->data);
		ptr=ptr->next;
		if(ptr!=NULL) printf("->");
	}
	printf("\n\n");
}

void main()
{
	create_linkedl();
	
	printl();

	add_node();

	printl();
}