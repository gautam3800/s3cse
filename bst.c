#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *left;
  struct node *right;
}node;
node *root=NULL;
void insert(){
  int x,c=1,temp;
  node *newnode,*t;
  do{
    t=root;
    newnode=(node*)malloc(sizeof(node));
    newnode->left=NULL;
    newnode->right=NULL;
    printf("Enter node: ");
    scanf("%d",&x);
    if (t==NULL){  
      newnode->data=x;
      root=newnode;
      printf("Node Entered at root\n\n"); 
    }
    else{
      while(t!=NULL){
	if (x<t->data){
	  if(t->left==NULL){
	    temp=t->data;
	    newnode->data=x;
	    t->left=newnode;
	    printf("Node Entered to the left of %d\n\n",temp);
	    break;
	  }
	  else
	    t=t->left;
	}
	else if(x>t->data){
	  if(t->right==NULL){
	    temp=t->data;
	    newnode->data=x;
	    t->right=newnode;
	    printf("Node Entered to the right of %d\n\n",temp);
	    break;
	  }
	  else
	    t=t->right;
	}
	else{
	  printf("Duplicate Node\n\n");
	  break;
	}
      }
    }
    printf("Enter choice\n1.Add node\n0.Finish\n\n");
    scanf("%d",&c);
  }while(c);
}
void preorder(node *t){
  if (t!=NULL){
    printf("%d ",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}
void inorder(node *t){
  if (t!=NULL){
    inorder(t->left);
    printf("%d ",t->data);
    inorder(t->right);
  }
}
void postorder(node *t){
  if (t!=NULL){
    postorder(t->left);
    postorder(t->right);
    printf("%d ",t->data);
  }
}
void search(int x){
  int flag=0;
  node *t=root;
  while (t!=NULL){
    if(x==t->data){
      flag=1;
      printf("Number is present\n");
      break;
    }
    else if(x<t->data)
      t=t->left;
    else
      t=t->right;
  }
  if (flag==0)
    printf("Number is not present\n");
}
void delete(int x){
  int flag=0;
  node *t=root,*t1=root;
  while (t!=NULL){
    if(x==t->data){
      flag=1;
      break;
    }
    else if(x<t->data){
      t1=t;
      t=t->left;
    }
    else{
      t1=t;
      t=t->right;
    }
  }
  if (flag==0)
    printf("Number is not present\n");
  else{
    printf("%d is deleted\n",t->data);
    if (t->left==NULL&&t->right==NULL){
      if(t==root){
	root=NULL;
      }
      else{
	if (t1->left==NULL){
	  t1->right=NULL;
	}
	else if ((t1->left)->data==t->data){
	  t1->left=NULL;
	}
	else{
	  t1->right=NULL;
	}
      }
    }
    else if(t->left!=NULL&&t->right==NULL){
      if ((t1->left)->data==t->data){
	t1->left=t->left;
      }
      else{
	t1->right=t->left;
      }
    }
    else if(t->left==NULL&&t->right!=NULL){
      if ((t1->left)->data==t->data){
	t1->left=t->right;
      }
      else{
	t1->right=t->right;
      }
    }
    else{
      int i;
      node *succ;
      succ=t->right;
      while(succ->left!=NULL){
	succ=succ->left;
      }
      i=succ->data;
      delete(succ->data);
      t->data=i;
    }
  }
}
int main(){
  int c,x;
  insert();
  printf("\n1.Preorder Traversal\n2.Inorder traversal\n3.Postorder traversal\n4.Search\n5.Delete\n0.Exit");
  while (c){
    printf("\nEnter choice: ");
    scanf("%d",&c);
    if(c==1){
      preorder(root);
      printf("\n");
    }
    else if(c==2){
      inorder(root);
      printf("\n");
    }
    else if(c==3){
      postorder(root);
      printf("\n");
    }
    else if(c==4){
      printf("\nEnter number to be searched: ");
      scanf("%d",&x);
      search(x);
    }
    else if(c==5){
      printf("\nEnter number to be deleted: ");
      scanf("%d",&x);
      delete(x);
    }
  }
  return 0;
}
