#include <bits/stdc++.h>
using namespace std;
class act
{
	public:
	int start;
	int finish;
	int index;
	char done;
	act(int s,int f,int i)
	{
		start=s;finish=f;index=i;done='0';
	}
};
bool cmp(act i1,act i2)
{
	return (i1.index<i2.index);
}
bool comp(act i1,act i2) 
{ 
    return (i1.finish < i2.finish); 
} 
int main()
{
	int num;
	cin>>num;
	for(int p=0;p<num;p++)
	{
		vector <act> v;
		int n;
		cin>>n;
		int *s=new int[n];
		int *f=new int [n];
		for(int i=0;i<n;i++)
		{
			cin>>s[i]>>f[i];
			v.push_back(act(s[i],f[i],i+1));	
		}
		sort(v.begin(),v.end(),comp);
		//cout<<(v.begin())->index<<" ";
		int prevc=INT_MIN;
		int prevj=INT_MIN;
		char fi='C';
		char se='J';
		for(auto i=v.begin();i!=v.end();i++)
		{
			//cout<<"i->start: "<<i->start<<" prevc: "<<prevc<<" prevj: "<<prevj<<"\n";
			if(i->start >= prevc)
			{
				//cout<<(i)->index<<" ";
				if(p!=2)
					i->done=fi;
				else
					i->done=se;
				prevc=(i)->finish;
			}
			else
			{
				if(i->start >= prevj)
				{
					if(p!=2)
						i->done=se;
					else
						i->done=fi;
					prevj=(i)->finish;
				}
			}
		}
		cout<<"Case #"<<p+1<<": ";
		int set=0;
		for(auto i=v.begin();i!=v.end();i++)
		{
			if(i->done=='0')
			{
				cout<<"IMPOSSIBLE";
				set=1;
				break;
	
			}		
		}
		sort(v.begin(),v.end(),cmp);
		if(set==0)
		{
			for(auto i=v.begin();i!=v.end();i++)
			{
				cout<<i->done;
			}
		}
		cout<<"\n";
	}
}
