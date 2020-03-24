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
void inorder(Node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<" "<<root->data;
	inorder(root->right);

}
Node  *insert(Node *root,int x)
{
	if(root==NULL)
		return new Node(x);
	if(x<root->data)
		root->left=insert(root->left,x);
	else
		root->right=insert(root->right,x);
	return root;
}
Node *search(Node *root,int x)
{
	if(root==NULL)
		return NULL;
	if(root->data==x)
		return root;
	if(x<root->data)
		return search(root->left,x);
	else
		return search(root->right,x);
}
Node *minvalue(Node *root)
{
	Node *cur=root;
	while(cur&&cur->left!=NULL)
		cur=cur->left;
	return cur;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int data) 
{ 
	if (root == NULL)  return ; 
	if (root->data == data) 
	{ 
		if (root->left != NULL) 
		{ 
			Node* tmp = root->left; 
			while (tmp->right) 
			tmp = tmp->right; 
			pre = tmp ; 
		} 
		if (root->right != NULL) 
		{ 
			Node* tmp = root->right ; 
			while (tmp->left) 
			tmp = tmp->left ; 
			suc = tmp ; 
		} 
		return ; 
	}
	if (root->data > data)
	{ 
		suc = root ; 
		findPreSuc(root->left, pre, suc, data) ; 
	} 
	else
	{ 
		pre = root ; 
		findPreSuc(root->right, pre, suc, data) ; 
	} 
} 
Node *deletenode(Node*root,int x)
{
	if(root==NULL)
		return NULL;
	if(x<root->data)
		root->left= deletenode(root->left,x);
	else
		if(x>root->data)
			root->right= deletenode(root->right,x);
		else
		{
			if(root->left==NULL)
			{
				Node *tmp=root->right;
				free(root);
				return tmp;
			}
			else 
				if(root->right==NULL)
				{
					Node *tmp=root->left;
					free(root);
					return tmp;
				}
			Node *tmp=minvalue(root->right);
			root->data=tmp->data;
			root->right=deletenode(root->right,tmp->data);			
		}
	return root;
}
Node *lca(Node *root,int n1,int n2)
{
	if(root==NULL)
		return NULL;
	if(root->data>n1&&root->data>n2)
		return lca(root->left,n1,n2);
	if(root->data<n1&&root->data<n2)
		return lca(root->right,n1,n2);
	return root;
}
int main()
{
	Node *root = NULL;
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,100);
	root=insert(root,80);
	cout << "\nInorder traversal of binary tree is \n"; 
	inorder(root);
	cout<<"\n";
	Node *x=search(root,40);
	if(x!=NULL)
		cout<<"found "<<x->data<<"\n";
	else
		cout<<"not found\n";
//	root=deletenode(root,70);
//	cout << "\nInorder traversal of binary tree is \n"; 
//	inorder(root);
//	root=deletenode(root,40);
//	cout << "\nInorder traversal of binary tree is \n"; 
//	inorder(root);

	Node* pre = NULL, *suc = NULL; 
	findPreSuc(root, pre, suc, 40); 
	if (pre != NULL) 
		cout << "Predecessor is " << pre->data << endl; 
	else
		cout << "No Predecessor";  
	if (suc != NULL) 
		cout << "Successor is " << suc->data; 
	else
		cout << "No Successor";
	return 0;
}
