#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* start1; // start pointer for linked list 1
struct node* start2; // start pointer for linked list 2
int n1, n2; // number of nodes in each linked list

void create_linkedl(struct node** start, int n)
{
    struct node* lnode; // pointer to current last node
    struct node* new = malloc(sizeof(struct node));
    printf("Enter data for 1st node: ");
    scanf("%d",&new->data);
    new->next=NULL;

    // now, There is only one node in linked list. Hence, first=last=new
    *start = new;
    lnode = new;

    // Now take input for remaining nodes
    for(int i=1;i<n;i++)
    {
        new = malloc(sizeof(struct node));
        printf("Enter data for Next Node: ");
        scanf("%d",&new->data);
        new->next=NULL;
        // Now assign address of new node to previous node (i.e., lastnode)
        lnode->next=new;
        // now change the pointer lastnode to actual lastnode
        lnode=new;
    }
    // loop will run until the number of nodes becomes value of n
}

void printl(struct node* ptr)
{
    // create a pointer which is going to travel node->to->node

    printf("\nLinked List:- Start->");
    while(ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
        if(ptr!=NULL) printf("->");
    }
    printf("\n\n");
}

void sort_linkedl(struct node* start)
{   
    struct node *i, *j;
    int temp;

    for (i = start; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

struct node* merge_sorted(struct node* list1, struct node* list2) {
    
    if (list1 == NULL) {
        return list2;
    }
    else if (list2 == NULL) {
        return list1;
    }
    
    struct node* merged = NULL;
    
    
    if (list1->data <= list2->data) {
        merged= list1;
        list1 = list1->next;
    }
    else {
        merged= list2;
        list2 = list2->next;
    }
    
    struct node* current= merged;
    
   
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current= current->next;
    }
    
    
    if (list1 == NULL) {
        current->next = list2;
    }
    else {
        current->next = list1;
    }
    
    return merged;
}


void main()
{
    printf("Linked list 1:\n");
    printf("Enter no.of nodes to create Linked List: ");
    scanf("%d", &n1);
    create_linkedl(&start1, n1);
    printl(start1);

    printf("Linked list 2:\n");
    printf("Enter no.of nodes to create Linked List: ");
    scanf("%d", &n2);
    create_linkedl(&start2, n2);
    printl(start2);

    sort_linkedl(start1);
    printf("Sorted Linked list 1:\n");
    printl(start1);

    sort_linkedl(start2);
    printf("Sorted Linked list 2:\n");
    printl(start2);

    struct node* merged;
	merged= merge_sorted(start1, start2);
	printf("Merged Linked List:\n");
	printl(merged);

}

