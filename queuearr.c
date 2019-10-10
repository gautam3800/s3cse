#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max],front=-1,rear=-1;

void enq()
{
  if(rear==max-1)
    {
      printf("\nNo space ");
    }
  else
    {
      int x;
      printf("\nEnter the data : ");
      scanf("%d",&x);
      if(front==-1)
	{
	  front++;
	  rear++;
	}
      else
	rear++;
      queue[rear]=x;
    }
}

void deq()
{
  if(front==-1)
    {
      printf("\nEmpty queue ");
    }
  else
    {
      printf("\n%d is dequeued ",queue[front]);
      if(front==rear)
	front=rear=-1;
      else
	front++;
    }
}

void display()
{
  int i;
  if(front==-1)
    {
      printf("\nEmpty queue ");
    }
  else
    {
      for(i=front;i<=rear;i++)
	printf("%d ",queue[i]);
    }
}

void main()
{
  int c;
  printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
  while(1)
    {
      printf("\nChoose an option : ");
      scanf("%d",&c);
      if(c==1)
	enq();
      else if(c==2)
	deq();
      else if(c==3)
	display();
      else if(c==4)
	exit(0);
      else
	printf("\nInvalid option.");
    }
}
