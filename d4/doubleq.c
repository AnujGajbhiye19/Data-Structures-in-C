#include<stdio.h>
int f=-1;
int r=-1;
int n=5;
int arr[5];
int data;

void enque_r(int data)
{
	if((f==0 && r==n-1) || r==f-1) printf("Queue Overflow\n");
	else
	{
		if(f==-1) f=0;
		r=(r+1)%n;
		arr[r]=data;
		printf("%d is Enqueued at Rear || F=%d || R=%d\n",arr[r],f,r);
	}
}

int deque_f()
{
	if(f==-1) printf("Queue Underflow\n");
	else
	{
		if(r==f)
		{
			printf("%d is Dequeued From Front || F=-1 || R=-1\n",arr[f]);
			f=-1;
			r=-1;
		}
		if(f==n-1)
		{
			printf("%d is Dequeued From Front || F=0 || R=%d\n",arr[f],r);
			f=0;
		}
		else
		{
			printf("%d is Dequeued From Front || F=%d || R=%d\n",arr[f],f+1,r);
			f=f+1;
		}
	}
}

void enque_f(int data)
{
	if((f==0 && r==n-1) || r==f-1) printf("Queue Overflow\n");
	else
	{
		if(f==-1)
		{
			f=0;
			r=0;
		}
		if(f==0) f=n-1;
		else f=f-1;
		arr[f]=data;
		printf("%d is Enqueued at Front || F=%d || R=%d\n",arr[f],f,r);
	}
}

int deque_r()
{
	if(f==-1) printf("Queue Underflow\n");
	else
	{
		if(f==r)
		{
			printf("%d is Dequeued From Rear || F=-1 || R=-1\n",arr[r]);
			f=-1;
			r=-1;
		}
		if(r==0)
		{
			printf("%d is Dequeued From Rear || F=%d || R=%d\n",arr[r],f,n-1);
			r=n-1;
		}
		else
		{
			printf("%d is Dequeued From Rear || F=%d || R=%d\n",arr[r],f,r-1);
			r=r-1;
		}
	}
}

void print()
{
	printf("Queue: ");
	if(f<=r)
	{
		for(int i=f;i<=r;i++) printf("%d ",arr[i]);
	}
	else
	{
		for(int i=0;i<=r;i++) printf("%d ",arr[i]);
		for(int i=f;i<n;i++) printf("%d ",arr[i]);
	}
	printf("\n");
}

void main()
{
	enque_r(5);
	enque_r(4);
	enque_f(6);
	enque_f(1);
	enque_r(7);
	enque_f(2);

	print();

	deque_f();
	//print();
	deque_r();
	//print();
	deque_r();
	
	print();

	enque_f(2);
	enque_f(9);
	enque_f(10);

	print();
}
