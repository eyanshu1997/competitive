#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
void print(vector<int> a,string b,int c)
{
	string d=to_string(c);
	cout<<"the vector "<<b<<" "<<d<<" is \n";
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
bool cmp(int i,int j)
{return i<j;}
int main()
{
	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	for(int p=0;p<num;p++)
	{
		int n;
		cin>>n;
		vector <int>cm[n];
		vector <int>rw[n];
		int k=0,r=0,c=0;
		int *cset=new int[n];
		for(int i=0;i<n;i++)
			cset[i]=0;
		for(int i=0;i<n;i++)
		{
			int rset=0;
			for(int j=0;j<n;j++)
			{
				int tmp;
				cin>>tmp;
				if(rset!=1)
				{
					sort(rw[i].begin(),rw[i].end(),cmp);
					if(binary_search(rw[i].begin(),rw[i].end(),tmp))
					{
						//cout<<to_string(i)<<" rset is set\n";
						rset=1;
						r++;
					}
				}
				if(cset[j]!=1)
				{
					sort(cm[j].begin(),cm[j].end(),cmp);
					if(binary_search(cm[j].begin(),cm[j].end(),tmp))
					{
						//cout<<to_string(j)<<" cset is set\n";
						c++;
						cset[j]=1;
					}

				}
				rw[i].push_back(tmp);
				cm[j].push_back(tmp);
				//print(rw[i],"rw",i);
				//print(cm[j],"cm",j);
				
				if(i==j)
					k=k+tmp;
			}
		}
		cout<<"CASE #"<<p+1<<": "<<k<<" "<<r<<" "<<c<<"\n";
	}
}
