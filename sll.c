#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *link;
}node;
node *head=NULL;

void insert(int x,int n){
  printf("\n");
  node *newnode;
  newnode=(node*)malloc(sizeof(node));
  if (newnode==NULL){
    printf("Insufficient memory");
    exit(0);
  }  
  else{
    newnode->data=x;
    if (head==NULL){
      if (n==0){
	newnode->link=NULL;
	head=newnode;
      }
      else
	printf("Invalid position");
    }
    else{
      if (n==0){
	newnode->link=head;
	head=newnode;
      }
      else{
	int c=0,flag=0;
	node *t;
	t=head;
	while(t!=NULL){
	  if (c==(n-1)){
	    flag=1;
	    newnode->link=t->link;
	    t->link=newnode;
	    break;
	  }
	  c++;
	  t=t->link;
	}
	if (flag==0)
	  printf("Invalid position");
      }
    }
  }
  printf("\n");
}

void delete(int n){
  printf("\n");
  if (head==NULL){
    printf("Empty list\n");
  }
  else if(n==0){
    head=head->link;
  }
  else{
    node *t1=head,*t2=head;
    int c=0,flag=0;
    while(t1!=NULL){
      if (c==n){
	flag=1;
	t2->link=t1->link;
	free(t1);
	break;
      }
      c++;
      t2=t1;
      t1=t1->link;
    }
    if (flag==0)
      printf("Invalid position");
  }
  printf("\n");
}

void search(int x){
  printf("\n");
  if (head==NULL)
    printf("Empty list\n");
  else{
    node *t;
    int c=0,flag=0;
    t=head;
    while (t!=NULL){
      if(t->data==x){
	printf("Data found at position %d",c);
	flag++;
	break;
      }
      c++;
      t=t->link;
    }
    if(flag==0)
      printf("Not found");
  }
  printf ("\n");
}

void traverse(){
  printf("\n");
  if (head==NULL)
    printf("Empty list\n");
  else{
    node *t;
    t=head;
    while (t!=NULL){
      printf("%d ",t->data);
      t=t->link;
    }
  }
  printf ("\n");
}

int main(){
  int c,x,n;
  printf("\n1. Insertion\n2. Deletion\n3. Search\n4. Traversal\n5. Exit: \n");
  while (1){
    printf("\nEnter option: ");
    scanf("%d",&c);
    if (c==1){
      printf("\nEnter position: ");
      scanf("%d",&n);
      printf("\nEnter data: ");
      scanf("%d",&x);
      insert(x,n);
    }
    else if (c==2){
      printf("\nEnter position to be deleted: ");
      scanf("%d",&n);
      delete(n);
    }
    else if (c==3){
      printf("\nEnter data to be searched: ");
      scanf("%d",&x);
      search(x);
    }
    else if (c==4)
      traverse();
    else if (c==5)
      break;
  }
  return 0;
}
