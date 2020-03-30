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
			cout<<"right child exists "<<(*right).ch<<"\n";

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

void print_p(priority_queue<ip, vector<ip>,cmp> arr,string s)
{
	priority_queue<ip, vector<ip>,cmp> pq=arr;
	cout<<"the priority queue"<<s<<" is\n ";
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
		priority_queue<ip, vector<ip>,cmp> arr1;
		priority_queue<ip, vector<ip>,cmp> arr2;
		for(int i=0;n[i];i++)
		{
			cin>>t;
			ip *tmp=new ip(n[i],t);
			arr1.push(*tmp);
		}
		//print_p(arr1,"1");
		while(arr1.size()!=0||arr2.size()!=1)
		{
			ip *p1,*p2;
			if(arr1.empty())
			{
				//cout<<"extracting from 1\n";
				ip t2=arr2.top();
				p1=new 	ip(t2.ch,t2.freq,t2.left,t2.right);
				arr2.pop();
				t2=arr2.top();
				p2=new 	ip(t2.ch,t2.freq,t2.left,t2.right);
				arr2.pop();
			}
			else
			{
				if(arr2.empty())
				{
					ip t1=arr1.top();
					p1=new 	ip(t1.ch,t1.freq,t1.left,t1.right);
					arr1.pop();
					t1=arr1.top();
					p2=new 	ip(t1.ch,t1.freq,t1.left,t1.right);
					arr1.pop();
				}
				else
				{
					ip t1=arr1.top();
					ip t2=arr2.top();
					if(t1.freq<t2.freq)
					{
						p1=new 	ip(t1.ch,t1.freq,t1.left,t1.right);
						arr1.pop();
					}
					else
					{
						p1=new 	ip(t2.ch,t2.freq,t2.left,t2.right);
						arr2.pop();
					}
					if(arr2.empty())
					{
						t1=arr1.top();
						p2=p2=new 	ip(t1.ch,t1.freq,t1.left,t1.right);
						arr1.pop();
					}
					else
					{
						if(arr1.empty())
						{
							t2=arr2.top();
							p2=new 	ip(t2.ch,t2.freq,t2.left,t2.right);
							arr2.pop();
						}
						else
						{
							t1=arr1.top();
							t2=arr2.top();
							if(t1.freq<t2.freq)
							{
								p2=new 	ip(t1.ch,t1.freq,t1.left,t1.right);
								arr1.pop();
							}
							else
							{
								p2=new 	ip(t2.ch,t2.freq,t2.left,t2.right);
								arr2.pop();
							}
						}
					}
					
				}
			}
			//cout<<"here\n";
			int fr=(*p1).freq+(*p2).freq;
			//cout<<"new frerq is "<<fr<<"\n";
			ip *tmp =new ip('\n',fr);
			//(*tmp).print();
			(*tmp).left=p1;
			(*tmp).right=p2;
			arr2.push(*tmp);
			//print_p(arr1,"1");
			//print_p(arr2,"2");		
		}
//		print_p(arr);
		ip root=arr2.top();
		int ar[100], top = 0;
		printCodes(&root,ar,top);
		cout<<"\n";
	}
}
