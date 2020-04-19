#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long int
#define tr(a,x) for(auto a:x)
#define tri(a,x) for(auto a=x.begin();a!=x.end();a++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define fo(i,x) for(int i=0;i<x;i++)
#define p_b(x,i) x.push_back(i)
#define printe(i) cout<<i<<" "
#define printed(x,i) cout<< x  <<i<<"\n"
#define ip(s) vector <s>vec;for(int i=0;i<n;i++){s tmp;cin>>tmp;vec.push_back(tmp);}
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define newl cout<<"\n"
int min(int a,int b)
{
	return a<b;
}
using namespace std;
void rsolve(vi v,int d)
{
        vi dp(sz(v)+1); 
	dp[0]=0;
	//cout<<"dp"<<dp[0]<<"\n";
	for(int i=1;i<dp.size();i++)
	{
		int r=dp[i-1]%v[i-1];
		//cout<<" r is "<<r<<"\n";
		if(r==0)
		{
			dp[i]=dp[i-1];
		}
		else
		{
			dp[i]=dp[i-1]+r;
		}
	}

	cout<<dp[sz(v)];

}
/*
void rsolve(vi v,int d)
{
	reverse(all(v));
	tr(a,v)
	{
			d=d-(d%a);
	}
	cout<<d;
}*/
void solve() 
{
	int n,d;
	cin>>n>>d;
	ip(int);
	rsolve(vec,d);
}

int main()
{

	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	fo(i,num)
	{
    		cout << "Case #" << i+1 << ": ";
    		solve();
		cout<<"\n";
	}
}
