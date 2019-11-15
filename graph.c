#include<stdio.h>
#define MAX 10
int MAT[MAX][MAX],A[MAX],Q[MAX];
int n,r=-1,f=0;

void depth(int i,int vis[])
{
    if(i!=n){
        printf("%d ",A[i]);
        vis[i]=1;
        for(int j=0;j<n;++j)
	        if(!vis[j]&&MAT[i][j])
	            depth(j,vis);
}
    
} 
void breadth(int i,int vis[]){
    for(int j=0;j<n;++j)
    if(MAT[i][j] && !vis[j])
        Q[++r]=A[j];
    if(f<=r){
        vis[f]=1;
        breadth(Q[f++],vis);
    }
}

int main(void){
    int i,j,ch;
    int vis[MAX]={0};
    printf("Enter the no.of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;++i){
        printf("\nEnter the elements: ");
        scanf("%d",&A[i]);
    }
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;++i)
        for(j=0;j<n;++j){
	        scanf("%d",&MAT[i][j]);
        }
    while(1){
        printf("1. DFS\n2. BFS\n\3. EXIT\n");
        scanf("%d",&ch);
        for(i=0;i<n;++i)
	        vis[i]=0;
        if(ch==3)
	        break;
        else if(ch==1){
	        depth(0,vis);
		printf("\n");
	}
        else if(ch==2){
	        breadth(0,vis);
	        for(i=0;i<n;++i){
	            if(vis[i]){
		    		printf("%d ",A[i]);
		    }
	        }
		printf("\n");
	}
        else
	        printf("\nInavalid choice");
    }
}
