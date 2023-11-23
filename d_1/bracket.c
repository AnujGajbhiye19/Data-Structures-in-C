#include<stdio.h>
#include<string.h>
int top=-1;

void push(char arr[], char data,int size)
{
if(top==(size-1))
{
printf("Stack is full\n");
}
else
{
top++;
arr[top]=data;
printf("%c is inserted to stack\n",arr[top]);
}
}

void pop(char arr[],int size)
{
if(top==-1)
{
printf("Stack is already empty\n");
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
int n;
printf("Enter size of String: ");
scanf("%d",&n);
char arr[n];
printf("Enter String of Brackets: ");
scanf("%s",arr);

char str[n];

for(int i=0;i<n;i++)
{
if( arr[i]=='(' || arr[i]=='[' || arr[i]=='{' || arr[i]=='<' )
	push(str,arr[i],n);
}

for(int i=n-1;i>=0;i--)
{
if( str[top]=='(' && arr[i]==')' )
	pop(str,n);
if( str[top]=='[' && arr[i]==']' )
	pop(str,n);
if( str[top]=='{' && arr[i]=='}' )
	pop(str,n);
if( str[top]=='<' && arr[i]=='>' )
	pop(str,n);
}

if(top==-1)
	printf("VALID !!!");
else
	printf("NOT VALID !!!");

printf("\n");

}
