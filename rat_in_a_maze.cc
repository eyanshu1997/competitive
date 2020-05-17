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
bool issafe(pp a,ll n,vector<vi> &sol)
{
	if(a.first==0&&a.second==0)
		return false;
	if(a.first<n&&a.first>=0&&a.second<n&&a.second>=0)
		if(sol[a.first][a.second]==1)
			return true;
	return false;
}
vector<pair<pp,char>> generatemove(pp a,ll n,vector<vi> &sol)
{
	vector<pair<pp,char>> po;
	vpp kmove={{1,0},{0,-1},{0,1},{-1,0}};
	vector<char> M={'D','L','R','U'};
	
	for(int i=0;i<sz(kmove);i++)
	{
		pp x=a+kmove[i];
		if(issafe(x,n,sol))
			p_b(po,make_pair(x,M[i]));
	}
	return po;
}
int solvekt(pp a,vector<vi> &sol,ll n,vector<char> &move,vector<vector<char>> &moves)
{
	//op(moves);
	if(a.first==n-1&&a.second==n-1)
	{
		moves.push_back(move);
		return true;
	}
	int set=0;
	vector<pair<pp,char>> po=generatemove(a,n,sol);
//	cout<<"current is {"<<a.first<<","<<a.second<<"}\n";
//	tr(b,po)
//	cout<<b.second <<": {"<<b.first.first<<","<<b.first.second<<"}, ";
//	newl;
	//return true;
	tr(b,po)
	{
		sol[b.first.first][b.first.second]=0;
		p_b(move,b.second);
		int x=solvekt(b.first,sol,n,move,moves);
		if(x>0)
		{
			set=set+x;
		}
		sol[b.first.first][b.first.second]=1;
		move.pop_back();

	}
	return set;
}
void rsolve(ll n,vector<vi> sol)
{
	pp a={0,0};
	vector<vector<char>> moves;
	vector<char> move;
	int set=0;
	if(sol[0][0]==1)
		set=solvekt(a,sol,n,move,moves);
	if(set>0)
	{
		printf("set %d\n",set);
		fo(i,set){
		tr(a,moves[i])cout<<a;
		cout<<" ";
		}
//		opa(sol)
	}
	else
	{
		//opa(sol);
		cout<<"-1";
	}
}
void solve() 
{
	ll n;
	cin>>n;
	vector<vi> sol(n,vi(n,-1));
	fo(i,n)
		fo(j,n)
			cin>>sol[i][j];
	rsolve(n,sol);
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
