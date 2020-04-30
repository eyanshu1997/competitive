#include <bits/stdc++.h>
using namespace std;
class job
{
	public:
	int j;
	int d;
	int p;
	job(int jo,int de,int pr)
	{
		j=jo;
		d=de;
		p=pr;
	}
	void print()
	{
		cout<<j<<" "<<d<<" "<<p<<"\n";
	}
};
bool cmp(job a, job b)
{
	return a.p>b.p;
}
void jsp(vector<job> j)	
{
	sort(j.begin(),j.end(),cmp);
	int n=j.size();
	vector<int>dead(n,-1);
	int sum=0;
	int count=0;
	for(auto i:j)
	{
		for (int k=min(n, i.d)-1; k>=0; k--) 
		{
			if (dead[k]==-1) 
			{
				count++; 
				dead[k] = i.j;
				sum+=i.p;
				break;				
			}
		} 
	}
	cout<<count<<" "<<sum<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	while(num--)
	{
		int n;
		cin>>n;
		vector <job>jo;			
		for(int i=0;i<n;i++)
		{
			int j,d,p;
			cin>>j;
			cin>>d;
			cin>>p;
			job tmp=*(new job(j,d,p));
			jo.push_back(tmp);
		}
		jsp(jo);
	}
}
