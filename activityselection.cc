#include <bits/stdc++.h>
using namespace std;
class act
{
	public:
	int start;
	int finish;
	int index;
	act(int s,int f,int i)
	{
		start=s;finish=f;index=i;
	}
};
bool comp(act i1,act i2) 
{ 
    return (i1.finish < i2.finish); 
} 
  
int main()
{
	int num;
	cin>>num;
	while(num--)
	{
		vector <act> v;
		int n;
		cin>>n;
		int *s=new int[n];
		int *f=new int [n];
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>f[i];
			v.push_back(act(s[i],f[i],i+1));	
		}
		sort(v.begin(),v.end(),comp);
		cout<<(v.begin())->index<<" ";
		int prev=(v.begin())->finish;
		for(auto i=v.begin()+1;i!=v.end();i++)
		{
			if(i->start > prev)
			{
				cout<<(i)->index<<" ";
				prev=(i)->finish;
			}
		}
		cout<<"\n";
	}
}
