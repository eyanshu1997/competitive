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
#define newl cout<<"\n"
#define vpp vector<pair<int,int>>
using namespace std;


int get_change(int m,vector<int> dp) 
{
	vector<int> deno;
	p_b(deno,1);
	p_b(deno,3);
	p_b(deno,4);	
	dp[0]=0;
	for(int i=1;i<=m;i++)
	{
		tr(a,deno)
			if(i>=a)
			{
				//cout<<"for money "<<i<<" coin "<<a;newl;
				int n=dp[i-a]+1;
				//cout<<"n is"<<n;newl;
				if(n<dp[i])
					dp[i]=n;
			}
	}
	//tr(a,dp)printed(" ",a);newl;
	return dp[m];
}

int main() {
  int m;
  std::cin >> m;
  vector<int> dp(m+1,INT_MAX);
	//tr(a,dp)printed(" ",a);newl;
  std::cout << get_change(m,dp) << '\n';

}
