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
using namespace std;
int dp(vi &a,vi &b)
{
	vector<vi> dp(sz(a)+1,vi(sz(b)+1,INT_MAX)); 
	fo(i,dp.size())
		dp[i][0]=0;
	fo(j,dp[0].size())
		dp[0][j]=0;
	for(int i=1;i<dp.size();i++)
		for(int j=1;j<dp[0].size();j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(max(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
			}
		}
	//tr(a,dp)
	//{
	//	tr(b,a)
	//		cout<<b<<" ";
	//	newl;	
	//}
	//newl;
	return dp[sz(a)][sz(b)];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << dp(a, b) << std::endl;
}
