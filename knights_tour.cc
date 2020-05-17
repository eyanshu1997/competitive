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
#define opa(s) tr(a,s){op(a);newl;}
using namespace std;
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}  
bool issafe(pp a,ll n,vector<vi> sol)
{
	if(a.first<n&&a.first>=0&&a.second<n&&a.second>=0)
		if(sol[a.first][a.second]==-1)
			return true;
	return false;
}
vpp generatemove(pp a,ll n,vector<vi> &sol)
{
	vpp po;
	vpp kmove={{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};
	tr(b,kmove)
	{
		pp x=a+b;
		if(issafe(x,n,sol))
			p_b(po,x);
	}
	return po;
}
bool solvekt(pp a,ll x,vector<vi> &sol,ll n)
{
	if(x==n*n)
		return true;
	vpp po=generatemove(a,n,sol);
//	opa(sol)	
//	tr(a,po)
//	{
//		cout<<"{"<<a.first<<","<<a.second<<"}"<<" ";
//	}newl;
//	return true;
	tr(b,po)
	{
		sol[b.first][b.second]=x;
		if(solvekt(b,x+1,sol,n))
			return true;
		else
			sol[b.first][b.second]=-1;
	}
	return false;
}
void rsolve(ll n)
{
	int x=0;
	vector<vi> sol(n,vi(n,-1));
	sol[0][0]=x;
	x++;
	pp a={0,0};
	if(solvekt(a,x,sol,n))
		opa(sol)
	else
	{
//		opa(sol);
		printf("solutuion doesnt exist\n");
	}
}
void solve() 
{
	ll n;
	cin>>n;
	rsolve(n);
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
