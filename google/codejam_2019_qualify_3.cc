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
	void show()
	{
		cout<<start<<" ==> "<<finish<<" = "<<done<<"\n";
	}
};
char comple(char a)
{
	if(a=='J')
		return 'C';
	return 'J';
}
bool cmp(act i1,act i2)
{
	return (i1.index<i2.index);
}
bool comp(act i1,act i2) 
{ 
    return (i1.finish < i2.finish); 
} 
void print(vector <act> a)
{
	cout<<"the vector is\n";
	for(auto i=a.begin();i!=a.end();i++)
		i->show();
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
		int sol=0;
		for(int i=0;i<n;i++)
		{
			cin>>s[i]>>f[i];
			v.push_back(act(s[i],f[i],i+1));	
		}
		sort(v.begin(),v.end(),comp);
		//print(v);
		//cout<<(v.begin())->index<<" ";
		int count=0;
		for(auto i=v.begin();i!=v.end()-1;i++)
		{
			int set=0;
			vector<act>::iterator it;
			for(auto j=i+1;j!=v.end();j++)
			{
				if(j->start<i->finish)
				{
					set++;
					it=j;
				}
			}
			//cout<<"for i : "<<count++<<" set is "<<set<<"\n";
			if(set>=2)
			{
				sol=1;
				break;	
			}
			else
			{
				if(set==0)
				{
					if(i->done=='0')					
						i->done='C';
				}
				else
				{
					//cout<<"i is ";
					//i->show();
					//cout<<"it is ";
					//it->show();
					if(i->done=='0')
					{
						if(it->done!='0')
						{
							//cout<<"set i to "<<comple(it->done)<<"\n";
							i->done=comple(it->done);
						}						
						else
						{
							//cout<<"set i to c and it to j\n";
							i->done='C';
							it->done='J';
						}
					}
					else
					{
						if(it->done!='0')
						{
							sol=1;
							break;
						}
						else
						{
							//cout<<"set it to "<<comple(i->done)<<"\n";
							it->done=comple(i->done);
						}
					}
				}
			}
		}
		cout<<"Case #"<<p+1<<": ";
		if(sol==1)
		{
			cout<<"IMPOSSIBLE";
		}
		else
		{
			if((v.end()-1)->done=='0')
				(v.end()-1)->done='C';
			sort(v.begin(),v.end(),cmp);
			for(auto i=v.begin();i!=v.end();i++)
				cout<<i->done;
		}
		cout<<"\n";
	}
}
