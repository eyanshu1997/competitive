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
pp generatemove(pp a,char x)
{
	vpp kmove={{1,0},{0,-1},{0,1},{-1,0}};
	vector<char> M={'E','S','N','W'};
	fo(b,sz(M))
	{
		if(x==M[b])
		{
			a=a+kmove[b]; 
		}
	}
	return a;
}
int rsolve(ll x,ll y,string M,ll t)
{
	//cout<<"x is "<<x<<" y  is "<<y<<" t is "<<t<<" M is "<<M<<"\n"; 
	if(abs(x)+abs(y)<=t)
		return t;
	if(sz(M)==0)
		return -1;
	char a=M[sz(M)-1];
	pp re=generatemove(make_pair(x,y),a);
	M.pop_back();
	return rsolve(re.first,re.second,M,t+1);
}
void solve() 
{
	ll n,y;
	cin>>n>>y;
	string m;
	cin>>m;
	reverse(all(m));
	int re=rsolve(n,y,m,0);
	if(re!=-1)
		cout<<re;
	else
		cout<<"IMPOSSIBLE";
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
