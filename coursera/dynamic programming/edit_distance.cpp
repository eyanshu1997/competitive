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

int min(int a,int b,int c)
{
	int t;
	if(a<b)
		t=a;
	else
		t=b;
	if(c<t)
		t=c;
	return t;
}
int edit_distance(const string &str1, const string &str2) {
	vector<vi> dp(sz(str1)+1,vi(sz(str2)+1,INT_MAX)); 
	fo(i,dp.size())
		dp[i][0]=i;
	fo(j,dp[0].size())
		dp[0][j]=j;
	for(int i=1;i<dp.size();i++)
		for(int j=1;j<dp[0].size();j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+1);
			}
		}
	//tr(a,dp)
	//{
	//	tr(b,a)
	//		cout<<b<<" ";
	//	newl;	
	//}
	//newl;
	return dp[sz(str1)][sz(str2)];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
