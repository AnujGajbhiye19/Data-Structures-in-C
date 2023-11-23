#include<stdio.h>
int size=10;
int top=-1;

void push(int arr[], int data)
{
if(top==(size-1))
{
printf("Stack is full\n");
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
printf("Stack is already empty\n");
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
printf("|%3d|\n",arr[i]);
}

void insertsort(int arr[], int data)
{
if(arr[top]<data || top==-1)
{
push(arr,data);
return;
}
int x=pop(arr);

insertsort(arr,data);

push(arr,x);
}

void sort(int arr[])
{
if(top==0)
	return;
int x=pop(arr);
sort(arr);
insertsort(arr,x);
}

void main()
{
int arr[size];

push(arr,200);
push(arr,4);
push(arr,35);
push(arr,2);
push(arr,11);

print(arr);

sort(arr);

print(arr);
}
