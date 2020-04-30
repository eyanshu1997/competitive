/*
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
3
*/
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
	int ma=*max_element(all(y));
	//cout<<ma<<"\n";
	vector<vi> dp(ma+1,vi(ma+1,INT_MIN));
	fo(i,ma+1){
		dp[i][0]=0;dp[0][i]=0;dp[i][1]=1;}
	for(int j=1;j<ma+1;j++)
		dp[1][j]=j;
	for(int i=2;i<=ma;i++)
		for(int j=2;j<=ma;j++)
		{
			int mi=INT_MAX;
			for(int k=1;k<=j;k++)
			{
				int ma=max(dp[i-1][k-1],dp[i][j-k]);
				mi=min(mi,ma);
			}
			dp[i][j]=1+mi;
		}
	//tr(a,dp){op(a)newl;}
	for(int i=0;i<sz(x);i++)
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
