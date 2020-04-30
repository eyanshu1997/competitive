
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

void solve(string str)
{
//	op(x) op(y)
	int ma=sz(str);
	//cout<<ma<<"\n";
	vector<vi> dp(ma,vi(ma,INT_MIN));
	fo(i,ma){
		dp[i][i]=1;}

	for(int cl=2;cl<=ma;cl++)
		for(int i=0;i<ma-cl+1;i++)
		{
			int j=i+cl-1;
			if (str[i] == str[j] && cl == 2) 
				dp[i][j] = 2; 				
			else 
				if (str[i] == str[j]) 
					dp[i][j] = dp[i+1][j-1] + 2; 
				else
					dp[i][j] = max(dp[i][j-1], dp[i+1][j]); 
		}
	//tr(a,dp){op(a)newl;}
	//cout<<dp[0][ma-1]<<"\n";
	int i=0,j=ma-1;
	int cl=j-i+1;
	vector<char> tmp;
	while(cl>=2)
	{
		if (str[i] == str[j] && cl == 2)
		{
			//	cout<<"i is "<<i<<" j is "<<j<<"\n";
			p_b(tmp,str[i]);
			i=i+1;j=j-1;
		}
		else
		{
			if(str[i]==str[j])
			{
			//cout<<"i is "<<i<<" j is "<<j<<"\n";
				p_b(tmp,str[i]);
				i=i+1;j=j-1;
			}
			else
			{
				if(dp[i][j-1]>dp[i+1][j])
					j=j-1;
				else
					i=i+1;
			}
		}
		cl=j-i+1;
	}
	reverse(all(tmp));
	string res="";
	if(ma%2!=0)
		p_b(res,str[i]);
	fo(x,sz(tmp))
	{
		string t="";
		p_b(t,tmp[x]);
		res=t+res;
		p_b(res,tmp[x]);
	}
	cout<<res<<"\n";	
}
int main()
{
	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	fo(i,num)
	{
		string str;
		cin>>str;
		solve(str);
	}
}
