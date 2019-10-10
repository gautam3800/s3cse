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

int binary(int arr[],int x,int f,int l)
{
  if(f<=l)
  { 
    int m;
    m=(f+l)/2;
    if(arr[m]==x){
      return m;
    }
    else if(arr[m]>x)
       return binary(arr,x,f,m-1);
    else
       return binary(arr,x,m+1,l);
  }
  return -1;
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
   sort(arr,n);
   int flag=binary(arr,x,0,n-1);
   if (flag==-1)
      printf("Element not found\n");
   else
     printf("Element found \n");
} 

