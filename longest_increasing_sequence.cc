#include <bits/stdc++.h>
#define pp pair<ll,ll>
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
#define op(s) for(auto i:s) cout<<i<<" ";cout<<"\n";
#define vi vector<ll>
#define vpp vector<pair<ll,ll>>
#define newl cout<<"\n"
using namespace std; 
void rsolve(vi v)
{
	vi dp(sz(v));
	dp[0]=1;
	fo(i,sz(v))
	{
		dp[i]=1;
		fo(j,sz(v))
		{
			if(v[i]>v[j]&&dp[j]+1>dp[i])
				dp[i]=dp[j]+1;
		}
	}
	cout<<*max_element(all(dp));
}
void solve() 
{
	int n;
	cin>>n;
	ip(ll);
	rsolve(vec);
}

int main()
{

	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	fo(i,num)
	{
    		solve();
		cout<<"\n";
	}
}
