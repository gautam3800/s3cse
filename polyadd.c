#include<stdio.h>
#include<stdlib.h>
struct node
{
	int cof;
	int exp;
	struct node* next;
};
struct node* insert(int n,struct node* head)
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	struct node* ptr;
	int d;
	printf("Enter the co-efficicent of x^%d : ",n);
	scanf("%d",&d);
	newnode->cof=d;
	newnode->exp=n;
	newnode->next=NULL;
	head=newnode;
	ptr=head;	
	for(int i=n-1;i>=0;i--)
	{
		printf("Enter the co-efficient of x^%d : ",i);
		scanf("%d",&d);
		if(d!=0)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			ptr->next=newnode;
			ptr=newnode;			
			newnode->cof=d;
			newnode->exp=i;
			newnode->next=NULL;
		}
 	}
	return head;
	
}
struct node* polyadd(struct node* phead,struct node* qhead)
{
	int i=1;
	struct node* newnode;
	struct node* rhead;
	struct node* rptr;
	struct node* pptr;
	struct node* qptr;
	pptr=phead;
	qptr=qhead;
	while(pptr!=NULL || qptr!=NULL)
	{
		if((pptr->exp)>(qptr->exp))
		{			
			newnode=(struct node*)malloc(sizeof(struct node*));
			newnode->cof=pptr->cof;
			newnode->exp=pptr->exp;
			newnode->next=NULL;
			if(i==1)	
			{
				rhead=newnode;
				rptr=rhead;
				i++;
				pptr=pptr->next;
				continue;
			}	
			rptr->next=newnode;
			rptr=newnode;
			pptr=pptr->next;
		}
		else if((pptr->exp)<(qptr->exp))
		{			
			newnode=(struct node*)malloc(sizeof(struct node*));
			newnode->cof=qptr->cof;
			newnode->exp=qptr->exp;
			newnode->next=NULL;			
			if(i==1)	
			{
				rhead=newnode;
				rptr=rhead;
				i++;
				qptr=qptr->next;
				continue;
			}
			rptr->next=newnode;
			rptr=newnode;
			qptr=qptr->next;
		}
		else if((pptr->exp)==(qptr->exp))
		{
			newnode=(struct node*)malloc(sizeof(struct node*));			
			newnode->cof=pptr->cof+qptr->cof;
			newnode->exp=pptr->exp;
			newnode->next=NULL;
			if(i==1)	
			{
				rhead=newnode;
				rptr=rhead;
				i++;
				pptr=pptr->next;
				qptr=qptr->next;
				continue;
			}			
			rptr->next=newnode;
			rptr=newnode;
			pptr=pptr->next;
			qptr=qptr->next;			
		}
		if(qptr==NULL)
		{
			while(pptr!=NULL)
			{
				newnode=(struct node*)malloc(sizeof(struct node*));
				newnode->cof=pptr->cof;
				newnode->exp=pptr->exp;
				newnode->next=NULL;
				rptr->next=newnode;
				rptr=newnode;
				pptr=pptr->next;			
			}
		}
		else if(pptr==NULL)
		{
			while(qptr!=NULL)
			{
				newnode=(struct node*)malloc(sizeof(struct node*));
				newnode->cof=qptr->cof;
				newnode->exp=qptr->exp;
				newnode->next=NULL;
				rptr->next=newnode;
				rptr=newnode;
				qptr=qptr->next;			
			}
		}		
				
	}
	return rhead;
}
void traverse(struct node* rhead)
{
	struct node* rptr;
	rptr=rhead;
	while(rptr->next!=NULL)
	{
		printf("%dx^%d + ",rptr->cof,rptr->exp);
		rptr=rptr->next;
	}
	printf("%dx^%d\n",rptr->cof,rptr->exp);
}			
int main()
{
	struct node* phead;
	struct node* qhead;
	struct node* rhead;		
	int n;
	printf("Enter the highest degree of the polynomial 1 : ");
	scanf("%d",&n);
	phead=insert(n,phead);
	traverse(phead);
	printf("\nEnter the highest degree of the polynomial 2 : ");
	scanf("%d",&n);
	qhead=insert(n,qhead);	
	traverse(qhead);
	printf("\n");
	rhead=polyadd(phead,qhead);
	traverse(rhead);
}
