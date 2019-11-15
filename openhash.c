#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct node
{
  int data;
  struct node*link;
}node;

node *head[MAX]={NULL};
int n;

void insert(int key)
{
  int i=key%n;
  node *temp;
  node *newnode;
  newnode=(node*)malloc(sizeof(node));
  newnode->data=key;
  newnode->link=NULL;
  if(head[i]==NULL)
    head[i]=newnode;
  else{
    temp=head[i];
    while(temp->link!=NULL)
      {
	temp=temp->link;
      }
    temp->link=newnode;
  }
}

void display()
{
  int i;
  node *temp;
  for(i=0;i<n;i++)
    {
      printf("Position %d : ",i);
      if(head[i]!=NULL){
	printf("%d ",head[i]->data);
	temp=head[i];
	temp=temp->link;
	while(temp!=NULL){
	  printf("-> %d ",temp->data);
	  temp=temp->link;
	}
      }
      printf("\n");
    }
  printf("\n");
}

void search(int key)
{
  int i,flag=0;
  node *temp;
  i=key%n;
  if(head[i]!=NULL){
    if(head[i]->data==key)
      flag=1;
    temp=head[i];
    temp=temp->link;
    while(temp!=NULL){
      if(temp->data==key)
	flag=1;
      temp=temp->link;
    }
  }
  else
    flag=0;
  if(flag==1)
    printf("The element is present at position %d ",i);
  else
    printf("The element is not found");
  printf("\n");
}

void main()
{
  int key,op;
  printf("Enter size : ");
  scanf("%d",&n);
  printf("\n1.Insert \n2.Display \n3.Search \n4.Exit \n");
  while(1)
    {
      printf("Enter the option : ");
      scanf("%d",&op);
      if(op==1){
	printf("Enter the value to be inserted : ");
	scanf("%d",&key);
	insert(key);
      }
      else if(op==2)
	display();
      else if(op==3){
	printf("Enter the element to be searched : ");
	scanf("%d",&key);
	search(key);
      }
      else
	exit(0);
    }
}
