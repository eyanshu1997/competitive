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
#define op(s) for(auto i:s) cout<<i<<" ";
#define vi vector<ll>
#define vpp vector<pair<ll,ll>>
#define newl cout<<"\n"
#define opa(s) tr(a,s){op(a);}
using namespace std;
pp findnext(vector<vi> &sud,int x,int y)
{
//	cout<<"for find next\n";
	for(int j=y+1;j<9;j++)
	{
//		cout<<sud[x][j]<<" ";
		if(sud[x][j]==0)
			return make_pair(x,j);
	}
	for(int i=x+1;i<9;i++)
		for(int j=0;j<9;j++)
			if(sud[i][j]==0)
				return make_pair(i,j);
	return make_pair(-1,-1);
}
vi findvalues(vector<vi> &sud,int x,int y)
{
	vi z(10,0);
	for(int i=0;i<9;i++)
	{
//		cout<<sud[x][i]<<" ";
		z[sud[x][i]]=1;
	}
	fo(i,9)
	{
//		cout<<sud[i][y]<<" ";
		z[sud[i][y]]=1;
	}
//	cout<<"\nz is\n";
//	op(z);
	int si=x/3;
	int sj=y/3;
	si=si*3;
	sj=sj*3;
//	cout<<"start of x is "<<si<<" "<<sj<<"\n";
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{	
//cout<<sud[si+i][sj+j]<<" ";
			z[sud[si+i][sj+j]]=1;
		}
//	cout<<"\nz is\n";
//	op(z);
	vi r;
	for(int i=1;i<10;i++)
	{
		if(z[i]==0)
			p_b(r,i);
	}
	return r;
}
bool rsolve(vector<vi> &sud,int x,int y)
{
	vi values=findvalues(sud,x,y);
//	cout<<"x is & y is {"<<x<<","<<y<<"}\n";
//	cout<<"values are\n";
//	op(values)
//	newl;
//	cout<<"new sud is \n";
//	opa(sud);
//	return false;
	if(sz(values)==0)
		return false;
	tr(a,values)
	{
		sud[x][y]=a;
		if(x==8&&y==8)
			return true;
		pp next=findnext(sud,0,0);
		if(next.first==-1&&next.second==-1)
		return true;
		if(rsolve(sud,next.first,next.second))
			return true;
		sud[x][y]=0;
	}
	return false;
}
void solve() 
{
	vector<vi> sud(9,vi(9,0));
	fo(i,9)
		fo(j,9)
			cin>>sud[i][j];
//	opa(sud);
//	return;
	//cout<<"\n";
	pp next;
	if(sud[0][0]!=0)
		next=findnext(sud,0,0);
	else
		next={0,0};
//	cout<<"next are {"<<next.first<<","<<next.second<<"}\n";
//	return ;
	if(next.first==-1&&next.second==-1)
		opa(sud)
	else
	{
		rsolve(sud,next.first,next.second);
		opa(sud);
	}
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
