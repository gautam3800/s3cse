#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int a[SIZE],front=-1,rear=-1;

void enq(int x){
  if (front==(rear+1)%SIZE)
    printf("Queue is Full");
  else if (front==-1){
    front++;rear++;
    a[rear]=x;
  }
  else{
    if (rear==SIZE-1)
      rear=0;
    else
      rear++;
    a[rear]=x;
  }
  printf("\n");
}

void deq(){
  if (front==-1)
    printf("Empty Queue");
  else{
    printf("%d is deleted",a[front]);
    if (front==rear)
      front=rear=-1;
    else if(front==SIZE-1)
      front=0;
    else
      front++;
  }
  printf("\n");
}

void display(){
  if (front==-1)
    printf("Empty Queue");
  else if(front<=rear){
    for (int i=front;i<=rear;i++)
      printf("%d ",a[i]);
  }
  else{
    for (int i=front;i<SIZE;i++)
      printf("%d ",a[i]);
    for (int i=0;i<=rear;i++)
      printf("%d ",a[i]);
  }
  printf("\n");
}

int main(){
  int c,x;
  printf("1. enQUEUE\n2. deQUEUE\n3. DISPLAY\n4. Exit\n");
  while(1){
    printf("Enter option : ");
    scanf("%d",&c);
    if (c==1){
      printf("Enter Data: ");
      scanf("%d",&x);
      enq(x);
    }
    else if(c==2){
      deq();
    }
    else if(c==3){
      display();
    }
    else if(c==4){
      exit(0);
    }
    else
      printf("Invalid option ");
    printf("\n");
  }
}
