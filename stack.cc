#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* next;
};
void push(Node **root,int data)
{
	Node *tmp= new Node();
	tmp->data=data;
	tmp->next=*root;
	(*root)=tmp;
}
int isempty(Node *root)
{
	if(root=NULL)
		return 1;
	return 0;
}
int pop(Node **root)
{
	if(isempty(*root))
		return INT_MIN;
	int data=(*root)->data;
	Node *tmp=*root;
	(*root)=tmp->next;
	free(tmp);
	return data;
}
int peek(Node *root)
{
	if(isempty(root))
		return INT_MIN;
	return root->data;
}
int main()
{
	Node *root=NULL;
	
	push(&root, 10); 
	push(&root, 20); 
	push(&root, 30);
	cout << pop(&root) << " popped from stack\n";
	cout << "Top element is " << peek(root) << endl; 

	return 0;
}
