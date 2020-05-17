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
vi issafe(int n,vector<vi> edge,int cur,vi col)
{
	vi x;
	if(cur==0)
	{
		fo(i,n)
			p_b(x,i);
		return x;	
	}
	vi co(n,0);
	fo(i,n)
	{
		if(edge[col[cur-1]][i]==1)
			co[i]=1;
		if(edge[i][col[cur-1]]==1)
			co[i]=1;
	}
	fo(i,cur)
	{
		co[col[i]]=0;
	}
	fo(i,n)
	{
		if(co[i]==1)
			p_b(x,i);
	}
	//cout<<"inside safe\n";
	//op(x);
	//cout<<"exit \n";
	return x;
}
bool rsolve(int n,vector<vi> &edge,int cur,vi &col)
{
	if(cur==n)
	{
		//op(col)
		//opa(edge)
		//cout<<"col[cur-1]] is " <<col[cur-1]<<" col[0] is "<<col[0]<<" edge[col[cur-1]][col[0]] is "<<edge[col[cur-1]][col[0]]<<" "<<edge[col[0]][col[cur-1]]<<"\n";

		//if(edge[col[cur-1]][col[0]]==1||edge[col[0]][col[cur-1]]==1)
//			return true;
//		else
//			return false;
		return true;
	}
	vi po=issafe(n,edge,cur,col);
//	cout<<"col is \n";
//	op(col)
//	cout<<"op is\n";
//	op(po)
	//return true;
	tr(x,po)
	{
		col[cur]=x;
	//	op(col);
	//	return true;
		if(rsolve(n,edge,cur+1,col))
			return true;
		else
		col[cur]=-1;
	}
	return false;
}
void solve() 
{
	int n,e;
	cin>>n>>e;
	vector<vi> edge(n,vi(n,0));
	vi col(n,-1);
	fo(i,e)
	{
		int s,d;
		cin>>s>>d;
		edge[s-1][d-1]=1;
		edge[d-1][s-1]=1;
	}
	//opa(edge)
	if(!rsolve(n,edge,0,col))
		cout<<"0";
	else
		cout<<"1";
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
