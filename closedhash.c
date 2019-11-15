#include<stdio.h>
#define MAX 50
int SIZE;
int Hash[MAX];
int search(int);
void insert(int key)
{
  int i,a,k,flag=0;
  i=key%SIZE;
  k=i;
  if(Hash[i]==-1)
     Hash[i]=key;
    else
   {
    a=search(key);
    if(a==1)
     printf("\nelement already exists");
    else
    {
    i++;
    while(i<SIZE)
    {
     if(Hash[i]==-1)
      {
       Hash[i]=key;
       flag=1;
       break;
      }
     i++;
    }
    if(flag==0)
   {
    i=0;
    while(i<k)
    {
     if(Hash[i]==-1)
      {
       Hash[i]=key;
       flag=1;
       break;
      }
     i++;
    }
   }
    
   }
  if(flag==0&&a!=1)
     printf("\nTable full");
  }
}
void display()
{
  int i=0;
  while(i<SIZE)
  {
   printf(" Position %d:",i);
   if(Hash[i]!=-1)
     printf("\t%d",Hash[i]);
   printf("\n");
   i++;
 }
}
int search(int key)
{
 int pos,k,flag=0;
 struct node*temp;
 pos=key%SIZE;
 if(Hash[pos]==-1)
    return 0;
 else
 {
  while(pos<SIZE)
    {
     if(Hash[pos]==key)
      {
       return 1;
      }
     pos++;
    }pos=0;
    while(pos<k)
    {
     if(Hash[pos]==key)
      {
       return 1;
      }
     pos++;
    }
  return 0;
 }
}
   
int main(void)
{
 int c,x,a,ch,key;
 printf("Enter size of hashtable: ");
 scanf("%d",&SIZE);
 for(int i=0;i<SIZE;++i)
   Hash[i]=-1;
 while(1)
 {
  printf("MENU:\n1.Insert\n2.Display\n3.Search\n4.Exit\nEnter choice: ");
  scanf("%d",&c);
  if(c==4)
   break;
  else
  {
   switch(c)
   {
    case 1:printf("\nEnter element: ");
           scanf("%d",&x);
           insert(x);
           break;
    case 2:display();
           break;
    case 3:printf("\nEnter element to be searched for : ");
	   scanf("%d",&key);
           a=search(key);
           if(a==1)
            printf("\nfound\n");
           else
            printf("\nnot found\n");
	   break;
    default:printf("\nInvalid choice\n");
   }
  }
 }
}

