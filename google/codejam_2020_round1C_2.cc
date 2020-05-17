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
string rsolve(int u,vector<pair<string,string>> vec)
{
	vector<char> sol(10);
//	vector <char> chars(26);
//	chars[0]='A';
//	fo(i,26)
//		chars[i]=chars[0]+i;
//	tr(i,chars)
	//	printe(i);
	//vector<vector<char>>pos(10);
	//fo(i,10)
	//	pos[i]=chars;
	//opa(pos);
	set<char> all; 	
	tr(a,vec)
	{
		if(sz(a.first)==sz(a.second))
		{
			all.insert(a.second[sz(a.second)-1]);
			int set=0;
			int n=a.first[0]-'0';
			fo(i,n)
			{
				if(a.second[0]==sol[i])
					set=1;
			}
			if(set==0)
			{
				sol[n]=a.second[0];
			}
		}
	}
	//vector<char> al(all.begin(),all,end());
	//op(all);
	
	tr(i,all)
	{
		int set=0;
		tr(a,sol)
			if(a==i)
				set=1;
		if(set==0)	
			sol[0]=i;
	}
	//fo(i,sz(sol))
	//	cout<<"is is "<<i <<" "<<sol[i]<<"\n";
	//op(sol);
	string t="";
	tr(a,sol)
		p_b(t,a);
	return t;
}
void solve() 
{
	int n;
	cin>>n;
	set<pair<string,string>> ve;
	fo(i,10000)
	{
		string m;
		string p;
		cin>>m>>p;
		if(m!="-1")
		{
			ve.insert(make_pair(m,p));
		}
	}
	vector<pair<string,string>> vec(ve.begin(),ve.end());
	sort(all(vec));
	cout<<rsolve(n,vec);
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
