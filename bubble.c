#include<stdio.h>

void main()
{
  int a[50],n,i,j,t;
  printf("Enter the no. of elements : ");
  scanf("%d",&n);
  printf("Enter the elements : ");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(a[i]>a[j]){
	t=a[i];
	a[i]=a[j];
	a[j]=t;
      }
    }
  }
  printf("The sorted list is : ");
  for(i=0;i<n;i++)
    printf("%d\n",a[i]);
}
