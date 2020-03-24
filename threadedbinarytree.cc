#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	bool rightthread;
	Node(int x)
	{
		rightthread=false;
		data=x;
		left=NULL;
		right=NULL;
	}
	Node(int x,Node *y)
	{
		rightthread=true;
		data=x;
		left=NULL;
		right=y;
		
	}
};
Node *leftmost(Node *root)
{
	if(root==NULL)
		return NULL;
	Node *tmp=root;
	while(tmp->left!=NULL)
	{
		tmp=tmp->left;
	}
	return tmp;
}
void inorder(Node *root)
{
	if(root==NULL)
		return;
	Node *tmp=leftmost(root);
	while(tmp!=NULL)
	{
		cout<<" "<<tmp->data;	
		if(tmp->rightthread)
			tmp=tmp->right;
		else
			tmp=leftmost(tmp->right);
	}

}

int main()
{
	Node *root = new Node(1); 
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4,root->left); 
	root->left->right = new Node(5,root);

	cout << "\nInorder traversal of binary tree is \n"; 
	inorder(root);

}
