//smallest scalar vector sum

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
int min(int a,int b)
{
	return a<b;
}
using namespace std;
void rsolve(vi x,vi y)
{
	sort(all(x));
	sort(all(y),greater<int>());
	ll sum=0;
	fo(i,sz(x))
		sum=sum+(x[i]*y[i]);
	cout<<sum;
}
void solve() 
{
	int n;
	cin>>n;
	vi x(n),y(n);
	fo(i,n)
		cin>>x[i];
	fo(i,n)
		cin>>y[i];
	rsolve(x,y);
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
