#include<stdio.h>

void sort(int arr[],int n)
{
  int i,j,t;
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(arr[i]>arr[j]){
	t=arr[i];
	arr[i]=arr[j];
	arr[j]=t;
      }
    }
  }
}

void linear(int arr[],int n,int x)
{
   int i,flag=0;
   for(i=0;i<n;i++)
   {
     if(arr[i]==x)
     {  
        flag=1;
        printf("Element found at %d \n",i+1);
        break;
     }
   }
   if(flag==0)
   {
     printf("Element not found\n");
   }
}

void binary(int arr[],int n,int x)
{
  int f=0,l=n-1,m,flag=0,pos;
  while(l>=f)
  {
    m=(f+l)/2;
    if(arr[m]==x)
    {
      pos=m+1;
       flag=1;
       break;
    }
    else if(arr[m]>x)
       l=m-1;
    else
       f=m+1;
  }
  if(flag==1)
    printf("Element found at %d\n",pos);
  else
     printf("Element not found\n");
}

void main()
{
   int arr[50],i,n,x,m;
   printf("Enter the size of array : ");
   scanf("%d",&n);
   printf("Enter the elements : ");
   for(i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
   printf("Enter element to be searched : ");
   scanf("%d",&x);
   printf("Enter the method: 1.LINEAR SEARCH 2.BINARY SEARCH :- ");
   scanf("%d",&m);
   if(m==1)
     linear(arr,n,x);
   else if(m==2)
   {
     sort(arr,n);
     binary(arr,n,x);
   }
   else
     printf("Invalid method");
} 

