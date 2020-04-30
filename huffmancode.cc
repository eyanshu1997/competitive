#include <bits/stdc++.h>
using namespace std;

class ip
{
	public:
	char ch;
	int freq;
	ip *left,*right;	
	ip(char c,char f)
	{
		ch=c;freq=f;
		left=NULL;right=NULL;
	}
	ip(char c,char f,ip *l,ip *r)
	{
		ch=c;freq=f;
		left=l;right=r;
	}
	int getfreq()
	{return freq;}
	void print()
	{
		cout<<"char is "<<ch<<" freq is "<<freq<<"\n";
		if(left!=NULL)
			cout<<"leftchild exists "<<(*left).ch<<"\n";
		if(right!=NULL)
			cout<<"leftchild exists "<<(*right).ch<<"\n";

	}
};

class cmp
{
	public:
	int operator()(ip a,ip b)
	{
		return (a.freq>b.freq);
	}
};

void print_p(priority_queue<ip, vector<ip>,cmp> arr)
{
	priority_queue<ip, vector<ip>,cmp> pq=arr;
	cout<<"the priority queue is\n ";
	while (pq.empty() == false) 
	{ 
		ip p = pq.top(); 
		p.print();
		pq.pop(); 
	}  
}
bool isleaf(ip x)
{
	if(x.left==NULL || x.right==NULL)
		return true;
	return false;
}
void printCodes(ip *root, int arr[], int top)  
{ 
	if (root->left) 
	{   
		arr[top] = 0; 
		printCodes(root->left, arr, top + 1); 
	} 
	if (root->right) {   
		arr[top] = 1; 
		printCodes(root->right, arr, top + 1); 
	} 
	if (isleaf(*root)) 
	{   
		//cout<< root->ch <<": "; 
		int i; 
		for (i = 0; i < top; ++i) 
			cout<< arr[i]; 
		cout<<" "; 
	} 
}
int main()
{
	int num;
	cin>>num;
	while(num--)
	{
		string n;
		cin>>n;
		int t;
		priority_queue<ip, vector<ip>,cmp> arr;
		for(int i=0;n[i];i++)
		{
			cin>>t;
			ip *tmp=new ip(n[i],t);
			arr.push(*tmp);
		}
		//print_p(arr);
		while(arr.size()!=1)
		{
			ip t=arr.top();
			ip *p1=new ip(t.ch,t.freq,t.left,t.right);
			//(*p1).print();
			arr.pop();
			t=arr.top();			
			ip *p2=new ip(t.ch,t.freq,t.left,t.right);
			arr.pop();
			//(*p2).print();
			int fr=(*p1).freq+(*p2).freq;
			//cout<<"new frerq is "<<fr<<"\n";
			ip *tmp =new ip('\n',fr);
			//(*tmp).print();
			(*tmp).left=p1;
			(*tmp).right=p2;
			arr.push(*tmp);
			//print_p(arr);		
		}
//		print_p(arr);
		ip root=arr.top();
		int ar[100], top = 0;
		printCodes(&root,ar,top);
		cout<<"\n";
	}
}
