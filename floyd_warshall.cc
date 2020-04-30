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
void rsolve(vector<vi> v,int n)
{
	vector<vi> dp(v);
	fo(i,n)
		fo(j,n)
			fo(k,n)
			{
				if(dp[j][k]>dp[j][i]+dp[i][k]&&dp[j][i]!=INT_MAX&&dp[i][k]!=INT_MAX)
					dp[j][k]=dp[j][i]+dp[i][k];
			}
	tr(a,dp)
	{
		tr(x,a)
			if(x>9999999)
				cout<<"INF ";
			else
				cout<<x<<" ";
		newl;
	}
}
void solve() 
{
	int n;
	cin>>n;
	vector<vi> vec(n,vi(n,INT_MAX));
	fo(i,n)
		fo(j,n)
		{
			cin>>vec[i][j];
		}
	rsolve(vec,n);
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
