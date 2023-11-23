#include<stdio.h>
int size=5;
int top=-1;

void push(int arr[], int data)
{
if(top==(size-1))
{
printf("Stack is full");
}
else
{
top++;
arr[top]=data;
printf("%d is inserted to stack\n",arr[top]);
}
}

void pop(int arr[])
{
if(top==-1)
{
printf("Stack is already empty");
}
else
{
printf("Deleted Data from stack is %d\n",arr[top]);
top--;
}
}

void print(int arr[])
{
printf("\nRemaining Stack is:\n");
for(int i=top;i>=0;i--)
printf("%d\n",arr[i]);
}

void main()
{
int arr[size];

push(arr,50);
push(arr,40);
push(arr,30);
push(arr,20);
push(arr,10);

pop(arr);
pop(arr);
//pop(arr);

print(arr);
}
