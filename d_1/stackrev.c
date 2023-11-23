#include<stdio.h>
int size=5;
int top=-1;

void push(char arr[], char data)
{
if(top==(size-1))
{
printf("Stack is full");
}
else
{
top++;
arr[top]=data;
printf("%c is inserted to stack\n",arr[top]);
}
}

void pop(char arr[])
{
if(top==-1)
{
printf("Stack is already empty");
}
else
{
printf("Deleted Data from stack is %c\n",arr[top]);
top--;
}
}

void print(char arr[])
{
printf("\nRemaining Stack is:\n");
for(int i=top;i>=0;i--)
printf("%c\n",arr[i]);
}

void main()
{
char arr[5];

push(arr,'H');
push(arr,'E');
push(arr,'M');
push(arr,'L');
push(arr,'O');

print(arr);

printf("Reverse of String in Stack: ");
for(int i=4;i>=0;i--)
	printf("%c",arr[i]);
printf("\n");


}
