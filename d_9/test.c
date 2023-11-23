#include<stdio.h>
#include<stdlib.h>

// Sort the LinkedList

typedef struct node {

    int data;
    struct node* next;

} Node;

Node* search(Node* head , int data){

    while(head != NULL){
        if( head->data == data) return head;
        head = head->next;
    }

    return NULL;
}


Node* get_node(int data){

    Node* temp = (Node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node* insert_head(Node* newHead,Node* head){

    if(head == NULL){
        return newHead;
    }else {
        newHead->next = head;
    }

    return newHead;
}

Node* insert_middle( Node* newNode , Node* head , int data ){

    Node* curr = search(head , data);

    if( curr == NULL ) return head;

    newNode->next = curr->next; 
    curr->next = newNode;
    return head;    
}

Node* insert_last(Node* newNode , Node* head){
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    return head;
}


Node* delete(int data , Node* head){
    Node* prev = NULL;
    Node* temp = head;

    while(temp->data != data){
        prev = temp;
        temp = temp->next;
    }

    if( prev == NULL ){
        return head->next;
    }else {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

Node* sort(Node* head){

    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr;
        Node* smallest = curr;
        while(temp != NULL){
            if(temp->data < smallest->data) smallest = temp;
            temp =     temp->next;
        }

        int temp1 = curr->data;
        curr->data = smallest->data;
        smallest->data = temp1;
        curr = curr->next;
        
    }

    return head;
}

Node* merge(Node* head1 , Node* head2){

    if( head1 == NULL ) return head2;
    if(head2 == NULL) return head1;
    
    Node* head = NULL;

    if(head1->data <= head2->data){
        head = head1;
        head1 = head1->next;
    }else {
        head = head2;
        head2 = head2->next;    
    }

    Node* temp = head;
    while( head1 != NULL && head2 != NULL ){
        if( head1->data <= head2->data ){
            temp->next = head1;
            head1 = head1->next;
        }else {
            temp->next = head2;
            head2 = head2->next;
        }

        temp = temp->next;
    }

    while(head1 != NULL){
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;    
    }

    while(head2 != NULL){
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }

    return head;
}


void display(Node* head){

    while(head != NULL){
        printf("%d->",head->data);
        head = head->next;
    }

    printf("NULL\n");
}

 

void main(){

    int choice;
    
    Node* head1 = NULL;
    Node* head2 = NULL;

    while(1){
        printf("\n1.Insert an element in the first list\n");
        printf("\n2.Insert an element in the second list\n");
        //printf("\n2.Insert in the middle\n");
        //printf("\n3.Insert at last\n");
        //printf("\n4.Delete an element\n");
        printf("\n3.Sort the first linked list\n");
        printf("\n4.Sort the second linked list\n");
        printf("\n5.Merge the two list\n");
        printf("\n6.Display the first linked list\n");
        printf("\n7.Display the second linked list\n");

        printf("\nEnter the choice\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                int item;
                printf("\nEnter the element:\n");
                scanf("%d",&item);
                Node* newNode = get_node( item );
                head1 = insert_head(newNode,head1);
                break;
            }

            case 2:{
                int item;
                printf("\nEnter the element:\n");
                scanf("%d",&item);
                Node* newNode = get_node( item );
                head2 = insert_head(newNode,head2);
                break;
            }

            

    
            
            case 3:{
                head1 = sort(head1);
                break;
            }

            case 4:{
                head2 = sort(head2);
                break;
            }

            case 5:{
                head1 = merge(head1,head2);
                break;
            }


            case 6:{
                display(head1);
                break;
            }

            case 7:{
                display(head2);
                break;
            }
        }

        printf("\nDo you want to continue?\n");
        char ch;
        scanf(" %c",&ch);
        if(ch == 'n') break;
    }

}
