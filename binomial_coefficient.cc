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

void solve(vi x,vi y)
{
//	op(x) op(y)
	int ma=*max_element(all(x));
	//cout<<ma<<"\n";
	vector<vi> dp(ma+1,vi(ma+1));
	fo(i,ma+1){
		dp[i][0]=1;dp[i][i]=1;}
	dp[0][0]=1;
	for(int i=1;i<=ma;i++)
		for(int j=1;j<i;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
		}
	//tr(a,dp){op(a)newl;}
	for(int i=0;i<sz(x);i++)
	if(x[i]<y[i])
		cout<<0<<"\n";
	else
		cout<<dp[x[i]][y[i]]<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	int x,y;
	vi sx,sy;
	fo(i,num)
	{
		cin>>x>>y;
		p_b(sx,x);
		p_b(sy,y);
	}
	solve(sx,sy);
}
