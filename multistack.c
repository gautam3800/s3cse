#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max],top1=-1,top2=max;

void push1()
{
  if(top1+1==top2)
    printf("No space\n");
  else
    {
      top1++;
      printf("Enter a value : ");
      scanf("%d",&stack[top1]);
    }
}

void push2()
{
  if(top2-1==top1)
    printf("No space\n");
  else
    {
      top2--;
      printf("Enter a value : ");
      scanf("%d",&stack[top2]);
    }
}


void pop1()
{
  if(top1==-1)
    printf("Empty stack1\n");
  else
    top1--;
}

void pop2()
{
  if(top2==max)
    printf("Empty stack2\n");
  else
    top2++;
}

void display1()
{
  if(top1==-1)
    printf("Empty stack1\n");
  else
    {
      int i;
      for(i=top1;i>=0;i--)
        printf("%d\n",stack[i]);
    }
}

void display2()
{
  if(top2==max)
    printf("Empty stack2\n");
  else
    {
      int i;
      for(i=top2;i<max;i++)
        printf("%d\n",stack[i]);
    }
}


void main()
{
  int op;
  while(1)
    {
      printf("\n1. PUSH into stack1\n2. PUSH into stack2\n3. POP from stack1\n4. POP from stack2\n5. DISPLAY stack1\n6. DISPLAY stack2\n7. EXIT\n");
      printf("Enter option : ");
      scanf("%d",&op);
      if(op==1)
	push1();
      else if(op==2)
	push2();
      else if(op==3)
	pop1();
      else if(op==4)
	pop2();
      else if(op==5)
	display1();
      else if(op==6)
	display2();
      else if(op==7)
	exit(0);
      else
	printf("Invalid option\n");
    }
}
