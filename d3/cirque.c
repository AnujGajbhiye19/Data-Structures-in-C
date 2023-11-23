#include<stdio.h>
int f=-1;
int r=-1;
int n=5;
int arr[5];
int data;
int temp;

void enque(int data)
{
	if(r==f-1 || (f==0 && r==n-1)) printf("Queue Overflow\n");
	else
	{
		if(f==-1) f=0;
		r=(r+1)%n;
		arr[r]=data;
		printf("%d is Enqueued || F=%d || R=%d \n",arr[r],f,r);
	}
}

int deque()
{
	if(f==-1) printf("Queue Underflow\n");
	else
	{
		if(r==f)
		{
			printf("%d is Dequeued || F=-1 || R=-1\n",arr[f]);
			f=-1;
			r=-1;
		}
		if(f==n-1)
		{
			printf("%d is Dequeued || F=0 || R=%d\n",arr[f],r);
			f=0;
		}
		else
		{
			f=f+1;
			printf("%d is Dequeued || F=%d || R=%d\n",arr[f-1],f,r);
		}
	}
}

void print()
{
	if(f<=r)
	{
		printf("Queue: ");
		for(int i=f;i<=r;i++) printf("%d ",arr[i]);
		printf("\n");
	}
	else
	{
		printf("Queue: ");
		for(int i=0;i<=r;i++) printf("%d ",arr[i]);
		for(int i=f;i<n;i++) printf("%d ",arr[i]);
		printf("\n");
	}
}

void main()
{
	enque(5);
	enque(4);
	enque(6);
	enque(1);
	enque(7);
	enque(2);

	print();

	deque();
	deque();
	deque();
	
	print();

	enque(2);
	enque(9);
	enque(10);

	print();
}
