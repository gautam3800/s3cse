#include<stdio.h>
#define MAX 100
int a[MAX];

int merge(int lb,int mid,int ub)
{
  int i=lb,j=mid+1,k=0,temp[MAX];
  while((i<=mid)&&(j<=ub))
    {
      if(a[i]<=a[j])
	{
	  temp[k]=a[i];
	  k++;
	  i++;
	}
      else
	{
	  temp[k]=a[j];
	  k++;
	  j++;
	}
    }
  while(i<=mid)
    {
      temp[k]=a[i];
      i++;
      k++;
    }
  while(j<=ub)
    {
      temp[k]=a[j];
      j++;
      k++;
    }
  for(int i=lb,k=0;i<=ub;++i,++k)
    {
      a[i]=temp[k];
    }
}


void mergesort(int lb,int ub)
{
  int mid;
  if(lb<ub)
    {
      mid=(lb+ub)/2;
      mergesort(lb,mid);
      mergesort(mid+1,ub);
      merge(lb,mid,ub);
    }
}

void main()
{
  int n,i;
  printf("Enter the no. of elements in array : ");
  scanf("%d",&n);
  printf("Enter the elements of the array : ");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  mergesort(0,n-1);
  printf("The sorted array : ");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
