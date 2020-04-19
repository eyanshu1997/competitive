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
int min(int a,int b)
{
	return a<b;
}
using namespace std;
void rsolve(vi d)
{
	int count=0;
	fo(i,d.size()-1)
	{
		if(d[i+1]<0&&d[i]>0)
			count++;
	}
	cout<<count;
}
void solve() 
{
	int n;
	cin>>n;
	vector<int> h(n+1),d(n+1);
	fo(i,n)
	{
		int tmp;
		cin>>tmp;
		h[i]=tmp;
		if(i!=0)
		{
			d[i]=h[i]-h[i-1];
		}
	}
	rsolve(d);
}

int main()
{

	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	fo(i,num)
	{
    		cout << "Case #" << i+1 << ": ";
    		solve();
		cout<<"\n";
	}
}
