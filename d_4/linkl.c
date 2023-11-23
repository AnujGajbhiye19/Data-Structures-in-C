#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* next;
};

struct node* start;

void main()
{
struct node* ptr;
struct node* n1= malloc(sizeof(struct node));
struct node* n2= malloc(sizeof(struct node));
struct node* n3= malloc(sizeof(struct node));
struct node* n4= malloc(sizeof(struct node));
struct node* n5= malloc(sizeof(struct node));
struct node* n6= malloc(sizeof(struct node));

start=n1;

n1->data=10;
n1->next=n2;

n2->data=20;
n2->next=n3;

n3->data=30;
n3->next=n4;

n4->data=40;
n4->next=n5;

n5->data=50;
n5->next=n6;

n6->data=60;
n6->next=NULL;

ptr=start;
int i=1;
//printf("Address of 0th Node: %ls\n",((int*)n1));
while(ptr!=NULL)
{
	printf("Node: %d -> data: %d || Next Node Address: %p\n",i,ptr->data,((void*)ptr->next));
	ptr=ptr->next;
	i++;
}


}
