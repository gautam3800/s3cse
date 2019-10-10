#include<stdio.h>

void main()
{
  int a[50],n,i,j,key,pos,t;
  printf("Enter the no. of elements : ");
  scanf("%d",&n);
  printf("Enter the elements : ");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=1;i<n;i++){
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
  }
  printf("The sorted list is : ");
  for(i=0;i<n;i++)
    printf("%d\n",a[i]);
}
