#include <stdio.h>
#include <stdlib.h>

// Define the structure for the doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Define a function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Define a function to delete the nth node from the end of the doubly linked list
void deleteNthNodeFromEnd(struct Node** head, int n) {
    struct Node* current = *head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    int position = count - n + 1;
    if (position <= 0 || position > count) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        return;
    }
    current = *head;
    int i = 1;
    while (i < position && current != NULL) {
        current = current->next;
        i++;
    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

// Define a function to print the doubly linked list from head to tail
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Define the main function to test the deleteNthNodeFromEnd function
int main() {
    struct Node* head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;
    printf("Original doubly linked list: ");
    printList(head);
    deleteNthNodeFromEnd(&head, 2);
    printf("Doubly linked list after deleting the 2nd node from the end: ");
    printList(head);
    return 0;
}

