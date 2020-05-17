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
bool safe(ll x,vector<vi> b,ll l)
{
	if(b[x][l]==0)
	{
		return true;
	}
	return false;
}
void place(ll x,ll y,ll n,vector<vi> &board,int v)
{
	if(v==1)
		board[x][y]+=100;
	else
		board[x][y]-=100;
	fo(i,n)
	{
		if(i!=y)
		board[x][i]+=v;
		if(i!=x)
		board[i][y]+=v;
	}
	int j=y-1,k=y+1;
	for(int i=x-1;i>=0;i--,j--,k++)
	{
		if(j>=0)
			board[i][j]+=v;
		if(k<n)
			board[i][k]+=v;
	}
	j=y-1,k=y+1;
	for(int i=x+1;i<n;i++,j--,k++)
	{
		if(j>=0)
			board[i][j]+=v;
		if(k<n)
			board[i][k]+=v;
	}
}
bool nqueen(ll n,vector<vi> &board,ll l,vector<vpp> &res,vpp &rx)
{
	if(l==n)
	{
		cout<<"[";
		tr(a,rx)
		{
			cout<<a.first<<" ";
		}
		cout<<"] ";
//	tr(l,board){
//	op(l)newl;}
//	newl;
		res.push_back(rx);
		return true;
	}
//	cout<<"for l "<<l<<"\nrx is";
//	tr(a,)
//	{
//		cout<<"{ "<<a.first<<","<<a.second<<"} ";
//	}newl;
//	tr(l,board){
//	op(l)newl;}
//	newl;
	bool result=false;
	fo(i,
	{
		if(safe(i,board,l))
		{
			//cout<<i<<" "<<l<<"\n";
		p_b(rx,make_pair(i+1,l+1));
		place(i,l,n,board,1);
		//tr(l,board){
		//op(l)newl;}
		//newl;
		//if(l==2)
		//return;
			result=nqueen(n,board,l+1,res,rx)||result;
			rx.pop_back();
			place(i,l,n,board,-1);
		}
	}
	return result;
}
void rsolve(ll n)
{
	ll l=0;
	vector<vi> board(n,vi(n,0));
	vector<vpp> res;vpp rx;
	if(!nqueen(n,board,l,res,rx))
		cout<<"-1";
}
void solve()
{
	int n;
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
    		//cout << "Case #" << i+1<< ": ";
    		solve();
		cout<<"\n";
	}
}
