#include <bits/stdc++.h>
using namespace std;
int caltrain(vector<pair<int,int>> t)
{
	sort(t.begin(),t.end());
	int max=INT_MIN;
	int sum=0;
	for(auto a:t)
	{
		sum+=a.second;
		if(sum>max)
			max=sum;
	}
	return max;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	while(num--)
	{
		vector<pair<int,int>> tr;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			tr.push_back(make_pair(t,1));
		}
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			tr.push_back(make_pair(t,-1));
		}
		cout<<caltrain(tr)<<"\n";
	}
}
