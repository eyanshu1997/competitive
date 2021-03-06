#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	Node(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
};
void preorder(Node *root)
{
	if(root==NULL)
		return;
	cout<<" "<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<" "<<root->data;
	inorder(root->right);

}
void postorder(Node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<" "<<root->data;
}
void bfs(Node *root)
{
	queue<Node *>q;
	Node *tmp;
	q.push(root);
	while(q.empty()==false)
	{
		tmp=q.front();
		cout<<tmp->data<<" ";
		q.pop();
		if(tmp->left!=NULL)
			q.push(tmp->left);
		if(tmp->right!=NULL)
			q.push(tmp->right);
	}
}
int maxdepth(Node *root)
{
	if(root==NULL)
		return 0;
	int ldepth=maxdepth(root->left);
	int rdepth=maxdepth(root->right);
	if(ldepth>rdepth)
		return (ldepth+1);
	else
		return (rdepth+1);
}
int main()
{
	Node *root = new Node(1); 
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5);
	
	cout << "\nPreorder traversal of binary tree is \n"; 
	preorder(root);
	cout << "\nInorder traversal of binary tree is \n"; 
	inorder(root);
	cout << "\nPostorder traversal of binary tree is \n";
	postorder(root);
	cout << "\nBFS traversal of binary tree is \n";
	bfs(root);
	cout<<"\nmaxdepth is "<<maxdepth(root)<<"\n";
}
