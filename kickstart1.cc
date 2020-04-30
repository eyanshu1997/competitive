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
ll lo(ll n)
{
	if(n==0)
		return 0;
	else
		return log2(n)+1;
}
ll maxlo(ll a,ll b)
{
	if(lo(a)>lo(b))
		return lo(a);
	else
		return lo(b);
}
string converse(string a)
{
	string t="";
	tr(x,a)
	{
		switch(x)
		{
			case 'N':	t=t+'S';break;
			case 'S':	t=t+'N';break;
			case 'W':	t=t+'E';break;
			case 'E':	t=t+'W';break;
		}
	}
	return t;
}
string smin(string a,string b)
{
	//cout<<"checking "<<a<<" "<<b<<"\n";;
	if(a=="MAX"&&b=="MAX")return "MAX";
	if(a=="MAX")return b;
	if(b=="MAX")
	return a;
	if(a.size()<b.size())
		return a;
	return b;
}
string s(ll imax,ll jmax)
{	
	int pmax=maxlo(abs(imax),abs(jmax));
	string dp[abs(imax)+1][abs(jmax)+1]={"MAX"};
	//dp[0][0][0]="";
	for(int k=0;k<=pmax+1;k++)
	{
		cout<<"k is "<<k<<"\n";
		fo(i,imax+1)
			fo(j,jmax+1)
			{
				string a=dp[i][j];
				int item;
				item=i+pow(2,k);
				if(item<0)
				{
					item=abs(item);
					if(item<=imax&&dp[item][j]!="MAX")
						a=smin(converse(dp[item][j])+"W",a);
				}
				else
					if(item<=imax&&dp[item][j]!="MAX")
						a=smin(dp[item][j]+"E",a);
				item=i-pow(2,k);
				if(item<0)
				{
					item=abs(item);
					if(item<=imax&&dp[item][j]!="MAX")
						a=smin(converse(dp[item][j])+"E",a);
				}
				else
					if(item<=imax&&dp[item][j]!="MAX")
						a=smin(dp[item][j]+"W",a);
				item=j+pow(2,k);
				if(item<0)
				{
					item=abs(item);
					if(item<=imax&&dp[i][item]!="MAX")
						a=smin(converse(dp[i][item])+"S",a);
				}
				else
					if(item<=imax&&dp[i][item]!="MAX")
						a=smin(dp[i][item]+"N",a);
				item=j-pow(2,k);
				if(item<0)
				{
					item=abs(item);
					if(item<=imax&&dp[i][item]!="MAX")
						a=smin(converse(dp[i][item])+"N",a);
				}
				else
					if(item<=imax&&dp[i][item]!="MAX")
						a=smin(dp[i][item]+"S",a);
				dp[i][j]=a;
				cout<<"i "<<i<<" j "<<j<<" ("<<dp[i][j]<<")\n";
				//if(j==2)				
				//return dp[i][j];
			}
	}
	return dp[imax][jmax];
}
void rsolve(ll imax,ll jmax)
{
	string res=s(abs(imax),abs(jmax));
	if(res=="")
		cout<<"IMPOSSIBLE";
	else
		cout<<res;
}
void solve() 
{
	ll i,j;
	cin>>i>>j;
	rsolve(i,j);
}

int main()
{

	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	fo(i,num)
	{
    		cout << "Case #" << i+1<< ": ";
    		solve();
		cout<<"\n";
	}
}
