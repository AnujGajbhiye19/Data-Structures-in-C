//delete nth node from doubly linked list


#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data ;
   struct node *prev;
   struct node *next;
};

struct node *start=NULL;
struct node *last=NULL;

struct node* Create_Node()
{
   struct node *new=malloc(sizeof(struct node));
   printf("\nEnter The Data At Node:");
   scanf("%d",&new->data);
   new->prev=NULL;
   new->next=NULL;
   return new;
}

void Create_Doubly_List()
{
   int i,n;
   printf("\nEnter no. Nodes to Doubly linked list: ");
   scanf("%d",&n);
   struct node *new;
   new=Create_Node();
   start=new;
   last=new;
   
   for(i=1;i<n;i++)
   {
       new=Create_Node();
       last->next=new;
       new->prev=last;
       last=new;
    }
   


}


void Display()
{
   struct node *ptr;
   ptr=start;
   printf("\nThe Doubly Linked List: ");
   while(ptr!=NULL)
     {
       printf("-> %d",ptr->data);
      ptr=ptr->next;
   }
	printf("\n");
}

void main()
{
   Create_Doubly_List();
   Display();
   
}

