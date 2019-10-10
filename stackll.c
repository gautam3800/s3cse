#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
}node;
node *top=NULL;

void push(int x)
{
  node *newnode;
  newnode=(node*)malloc(sizeof(node));
  if (newnode==NULL){
    printf("Insufficient memory\n");
    exit(0);
  }
  else{
    newnode->data=x;
    newnode->link=top;
    top=newnode;
  }
}

void pop()
{
  if(top==NULL)
    printf("Empty stack\n");
  else{
    node *temp;
    temp=top;
    top=top->link;
    printf("The value popped is %d \n",temp->data);
    free(temp);
  }
}

void display()
{
  if(top==NULL)
    printf("Empty stack\n");
  else{
    node *temp;
    temp=top;
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
  printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT");
  while (1){
    printf("\nEnter option: ");
    scanf("%d",&c);
    if (c==1){
      printf("\nEnter data : ");
      scanf("%d",&x);
      push(x);
    }
    else if (c==2){
      pop();
    }
    else if (c==3){
      display();
    }
    else if (c==4)
      break;
  }
}
