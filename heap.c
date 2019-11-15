#include<stdio.h>
void heapify(int a[],int i,int n){
  int largest=i,lc=(2*i)+1,rc=(2*i)+2,temp;
  if (a[lc]>a[largest]&&lc<n)
    largest=lc;
  if (a[rc]>a[largest]&&rc<n)
    largest=rc;
  if (i!=largest){
    temp=a[i];
    a[i]=a[largest];
    a[largest]=temp;
    heapify(a,largest,n);
  }
}
void heapsort(int a[],int n){
  int i,temp;
  for (i=(n/2)-1;i>=0;i--){
    heapify(a,i,n);
  }
  for (i=n-1;i>=0;i--){
    temp=a[0];
    a[0]=a[i];
    a[i]=temp;
    heapify(a,0,i);
  }
}
int main(){
  int a[10],n,i;
  printf("Enter number of elements: ");
  scanf("%d",&n);
  printf("Enter elements: \n");
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  heapsort(a,n);
  printf("\n");
  for (i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
