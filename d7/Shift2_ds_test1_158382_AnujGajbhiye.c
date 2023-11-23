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

void Delete_Node()
{
   int i,pos;
   printf("\nEnter Pos. Of Node To Delete From end:");
   scanf("%d",&pos);
   struct node *ptr=last;
   for(i=1;i<pos;i++)
       ptr=ptr->prev;
  if(ptr->next==NULL)
  {
      struct node *temp;
      temp=last;
      last=last->prev;
      last->next=NULL;
      free(temp);
      printf("\nNode Deleted Success!!!.");
  }
  else if(ptr->prev==NULL)
  {
     struct node *temp;
     temp=start;
     start=start->next;
     start->prev=NULL;
     free(temp);
     printf("\nNode Deleted!!!.");
  }
  else
  {
    struct node *temp;
    temp=ptr;
  ptr->prev->next=ptr->next;
  ptr->next->prev=ptr->prev;
  free(temp);
    printf("\nNode Deleted!!!.");
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
   
   Delete_Node();
   Display();
}

