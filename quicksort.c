#include<stdio.h>
#define MAX 100
int a[MAX];


int partition(int lb,int ub)
{
  int pivot,left,right,temp;
  pivot=a[lb];
  left=lb;
  right=ub;
  while(left<right)
    {
      while((a[left]<=pivot)&&left<ub)
	left++;
      while((a[right]>pivot))
	right--;
      if(left<right)
	{
	  temp=a[right];
	  a[right]=a[left];
	  a[left]=temp;
	}
    }
  temp=a[lb];
  a[lb]=a[right];
  a[right]=temp;
  return right;
}

void quicksort(int lb,int ub)
{
  int p;
  if(lb<ub)
    {
      p=partition(lb,ub);
      quicksort(lb,p-1);
      quicksort(p+1,ub);      
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
  quicksort(0,n-1);
  printf("The sorted array : ");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
}
