#include<stdio.h>
int size=10;
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

int pop(int arr[])
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
return arr[top+1];
}

void print(int arr[])
{
printf("\nStack is:\n");
for(int i=top;i>=0;i--)
printf("%d\n",arr[i]);
}

void insert_at_bottom(int arr[], int data)
{
if(top==-1)
{
push(arr,data);
return;
}
int x=pop(arr);

insert_at_bottom(arr,data);

push(arr,x);

}

void main()
{
int arr[size];

push(arr,50);
push(arr,40);
push(arr,30);
push(arr,20);
push(arr,10);

insert_at_bottom(arr,100);

print(arr);
}
