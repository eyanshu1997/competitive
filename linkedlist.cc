#include<bits/stdc++.h>

using namespace std;

class Node 
{
public:
int data;
Node *next;
};

void printlist(Node *n)
{
	while(n!=NULL)
	{
		cout<<" "<<n->data;
		n=n->next;
	}
	cout<<"\n";
}
void push(Node **n,int data)
{
	Node *tmp=new Node();
	tmp->data=data;
	tmp->next=(*n);
	(*n)=tmp;
}
void addafter(Node *x,int data)
{
	Node *tmp=new Node();
	tmp->data=data;
	tmp->next=x->next;
	x->next=tmp;
}
Node *getlast(Node *n)
{
	if(n==NULL)
		return NULL;
	while(n->next!=NULL)
	{
		n=n->next;
	}
	return n;
}
void addlast(Node *n,int data)
{
	Node *l=getlast(n);
	Node *tmp=new Node();
	tmp->data=data;
	tmp->next=NULL;
	l->next	=tmp;
}
void deletenode(Node **no,int key)
{
	Node *n=*no;
	if(n==NULL)	
		return;
	if(n->data==key)
	{
		Node *tmp=n;
		free(tmp);
		(*no)=n->next;
		return;
	}
	while(n->next!=NULL)
	{
		if(n->next->data==key)
		{
			Node *tmp=n->next; 
			n->next=n->next->next;
			free(tmp);
			return;
		}
		n=n->next;
	}
	
}
void deleteposition(Node **no,int pos)
{
	int i=0 	;
	Node *n=*no;
	if(n==NULL)	
		return;
	if(pos==0)
	{
		Node *tmp=n;
		free(tmp);
		(*no)=n->next;
		return;
	}
	while(n->next!=NULL)
	{
		if(i==pos-1)
		{
			Node *tmp=n->next; 
			n->next=n->next->next;
			free(tmp);
			return;
		}
		i++;
		n=n->next;
	}
}
int getlength(Node *head)
{
	int count=0;
	while(head!=NULL)
	{
		count++;
		head=head->next;	
	}
	return count;
}
int main()
{
	Node *head=NULL;
	push(&head,10);
	push(&head,1);
	push(&head,5);
	addafter(head,7);
	addlast(head,0);
	printlist(head);
	//deletenode(&head,10);
	//deletenode(&head,5);
	deleteposition(&head,3);
	printlist(head);
	cout<<"length is : "<<getlength(head)<<"\n";
	return 0;
}
