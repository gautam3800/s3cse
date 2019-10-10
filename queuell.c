#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
}node;
node *front=NULL,*rear=NULL;

void enq(int x)
{
  node *newnode;
  newnode=(node*)malloc(sizeof(node));
  if (newnode==NULL){
    printf("Insufficient memory\n");
    exit(0);
  }
  else{
    newnode->data=x;
    newnode->link=NULL;
    if(front==NULL)
      {
	front=rear=newnode;
      }
    else
      {
	 rear->link=newnode;
	 rear=newnode;
      }
  }
}

void deq()
{
  if(front==NULL)
    printf("Empty stack\n");
  else{
    node *temp;
    temp=front;
    front=front->link;
    printf("The dequeued value is %d \n",temp->data);
    free(temp);
  }
}

void display()
{
  if(rear==NULL)
    printf("Empty stack\n");
  else{
    node *temp;
    temp=front;
    while(temp!=NULL){
      printf("->%d",temp->data);
      temp=temp->link;
    }
    printf("\n");
  }
}

void main()
{
  int c,x,n;
  printf("\n1. enQUEUE\n2. deQUEUE\n3. DISPLAY\n4. EXIT");
  while (1){
    printf("\nEnter option: ");
    scanf("%d",&c);
    if (c==1){
      printf("\nEnter data : ");
      scanf("%d",&x);
      enq(x);
    }
    else if (c==2){
      deq();
    }
    else if (c==3){
      display();
    }
    else if (c==4)
      break;
  }
}
