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
void rsolve(string str)
{
	int n=sz(str);
	vi dp(n,INT_MAX);
	vector<vector<bool>> p(n,vector<bool>(n));
	fo(i,n)
	{
		p[i][i]=true;
	}
	for(int cl=2;cl<=n;cl++)
		for(int i=0;i<n-cl+1;i++)
		{
			int j=i+cl-1;	
			if(cl==2)
				p[i][j]=(str[i] == str[j]);
			else
				p[i][j]=(str[i] == str[j])&&p[i+1][j-1];
			
		}
	fo(i,n)
		if(p[0][i]==true)
			dp[i]=0;
		else
			fo(j,i)
				if(p[j+1][i]==true &&1+dp[j]<dp[i])
					dp[i]=1+dp[j];
	cout<<dp[n-1];
}
void solve() 
{
	string x;
	cin>>x;

	rsolve(x);
}

int main()
{

	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	fo(i,num)
	{
    		///cout << "Case #" << i+1<< ": ";
    		solve();
		cout<<"\n";
	}
}
