#include<stdio.h>
int f=-1;
int r=-1;
int n;
int arr[10];
int data;
int temp;

void enque(int data)
{
	if(r==n-1)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		if(f==-1) f=0;
		r=r+1;
		arr[r]=data;
		printf("%d is Enqueued || F=%d || R=%d \n",arr[r],f,r);
	}
}

int deque()
{
	if(r==-1)
	{
		printf("Queue Underflow\n");
		return 0;
	}
	else
	{
		if(f==r)
		{
			f=-1;
			r=-1;
		}
		f+=1;
		printf("%d is Dequeued || F=%d || R=%d \n",arr[f-1],f,r);
		return arr[f-1];
	}
}

void print()
{
	printf("Queue: ");
	for(int i=f;i<=r;i++) printf("%d ",arr[i]);
	printf("\n");
}

void main()
{
	printf("Enter size of Queue: ");
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
	printf("Enter elements to Enque: ");
	scanf("%d",&data);
	enque(data);
	}

	print();

	printf("Enter no. of deque's: ");
	scanf("%d",&temp);
	for(int i=0;i<temp;i++) deque();

	print();
}
