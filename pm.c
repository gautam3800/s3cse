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
struct node* polymul(struct node* phead,struct node* qhead)
{
	int k=1;
	struct node *rhead,*shead,*pptr,*qptr,*rptr,*sptr,*tptr,*newnode;
	pptr=phead;
	qptr=qhead;
	while(pptr!=NULL)
	{
		qptr=qhead;
		while(qptr!=NULL)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->cof=pptr->cof * qptr->cof;
			newnode->exp=pptr->exp + qptr->exp;
			newnode->next=NULL; 	
			if(k==1)
			{
				k++;
				shead=newnode;
				sptr=shead;
				qptr=qptr->next;
			}
			else
			{	
				sptr->next=newnode;
				sptr=newnode;
				qptr=qptr->next;
			}
		}
		pptr=pptr->next;
	}
	k=shead->exp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->cof=shead->cof;
	newnode->exp=shead->exp;
	newnode->next=NULL;
	rhead=newnode;
	rptr=rhead;
	while((--k)!=-1)
	{
		int sum=0;
		newnode=(struct node*)malloc(sizeof(struct node));		
		rptr->next=newnode;
		rptr=newnode;
		sptr=shead->next;
		while(sptr!=NULL)
		{
			if(sptr->exp == k)
				sum=sum+ sptr->cof;
			sptr=sptr->next;
		}
		rptr->cof=sum;
		rptr->exp=k;
		rptr->next=NULL;
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
	rhead=polymul(phead,qhead);
	traverse(rhead);
}

