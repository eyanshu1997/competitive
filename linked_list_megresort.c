#include<stdio.h>
#include<stdlib.h>
struct Node {
int data;
struct Node *next;
}*head;
void print(struct Node *head)
{
	struct Node *x=head;
	while(x!=NULL)
	{
		printf(" %d",x->data);
		x=x->next;
	}
	printf("\n");	
}
void addelement(struct Node **x,int data	)
{
	struct Node *h=*x;
	struct Node *tmp = (struct Node *) malloc(sizeof(struct Node ));
	tmp->next=h->next;
	tmp->data=data;
	h->next=tmp;
}
void push(struct Node **x,int data	)
{
	struct Node *tmp = (struct Node *) malloc(sizeof(struct Node ));
	tmp->next=*x;
	tmp->data=data;
	*x=tmp;
}
struct Node *sortedmerge(struct Node *a,struct Node *b)
{
	struct Node *result=NULL;
	if(a==NULL)
		return (b);
	else if (b==NULL)
		return (a);
	if(a->data <= b->data)
	{
		result=a;
		result->next=sortedmerge(a->next,b);
	}
	else
	{
		result=b;
		result->next=sortedmerge(a,b->next);
	}
	return (result);

}
void frontbacksplit(struct Node *head,struct Node **a,struct Node **b)
{
	struct Node *slow,*fast;
	slow=head;
	fast=head->next;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			fast=fast->next;
			slow=slow->next;
		}
	}
	*a=head;
	*b=slow->next;
	slow->next=NULL;
	
}
void mergesort(struct Node **h)
{
	struct Node *head=*h;
	struct Node *a,*b;

	printf("sorting : ");
	print(head);	

	if(head==NULL || head->next==NULL)
		return;

	frontbacksplit(head,&a,&b);
	mergesort(&a);
	mergesort(&b);
	printf("a is ");
	print(a);
	printf("b is ");
	print(b);
	*h=sortedmerge(a,b);
	printf("after sorting ");
	print(head);
}

int main()
{
	head=NULL;
	push(&head,5);
	printf("hello\n");
	push(&head,10);
	push(&head,7);
	push(&head,9);
	push(&head,3);
	push(&head,1);
	print(head);
	mergesort(&head);
	print(head);
}
