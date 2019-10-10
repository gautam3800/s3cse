#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max],top1=-1;

void push()
{
  if(top1+1==max)
    printf("No space\n");
  else
    {
      top1++;
      printf("Enter a value : ");
      scanf("%d",&stack[top1]);
    }
}

void pop()
{
  if(top1==-1)
    printf("Empty stack\n");
  else
    top1--;
}

void display()
{
  if(top1==-1)
    printf("Empty list\n");
  else
    {
      int i;
      for(i=top1;i>=0;i--)
        printf("%d\n",stack[i]);
    }
}

void main()
{
  int op;
  while(1)
    {
      printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
      printf("Enter option : ");
      scanf("%d",&op);
      if(op==1)
	push();
      else if(op==2)
	pop();
      else if(op==3)
	display();
      else if(op==4)
	exit(0);
      else
	printf("Invalid option\n");
    }
}
