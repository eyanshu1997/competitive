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
int rsolve(vi v,ll m)
{
	if(sz(v)>m)
	{
		vpp count;
		fo(i,sz(v))
		{
			int set=0;
			fo(j,sz(count))
			{
				if(count[j].second==v[i])
				{
					//cout<<"found"<<j.second<<" "<<j.first<<"\n";;
					count[j].first=count[j].first+1;
					//cout<<"found"<<j.second<<" "<<j.first<<"\n";
					set=1;break;
				}
			}
			if(set==0)
			{
				//cout<<"i "<<v[i]<<"\n";
				count.push_back(make_pair(1,v[i]));	
			}
		}
		//return -1;
		sort(all(count));
		reverse(all(count));
		//tr(a,count)
		//cout<<a.first <<" "<<a.second<<"\n";
		int set=0;
		ll se=count.begin()->first;
		tr(a,count)
		{
			//cout<<"se is "<<se <<" "<<a.first<<"\n";
			if(a.first!=se)
			{//cout<<"set\n";
				set=1;}
		}
		ll sel;	
		vi::iterator x;
		if(set==1)
		{
			sel=count.begin()->second;
			x=lower_bound(all(v),sel);
			while(m!=0&&x+1!=v.end()&&*x==*(x+1))
			{
				m=m-1;
				x++;
			}
			//cout<<"m is "<<m<<" x is "<<*x<<"\n";
		}
		else
		{
			sel=v[0];
			x=lower_bound(all(v),sel);
		}

		//cout<<"sel is "<<sel<<"\n";;
		//return -1;
		int cnt=0;
		while(m!=0&&x!=v.end())
		{
			//cout<<"after selecting"<<*x<<"\n";
			cnt++;
			*x=*x-sel;
			m=m-1;
			x++;
			//op(v);
		}
		return cnt-1;
	}
	else
	{
		if(sz(v)==m)
			return 0;
		long double s=accumulate(v.begin(),v.end(),0);
		long double sel=s/m;
		auto x=lower_bound(all(v),sel);
//		cout<<"\nsel is "<<sel<<"\n";;
		//return -1;
		int cnt=0;
		//return -1;
		while(x!=v.end()&&m!=0)
		{
			long double a=*x;
			while(a>=sel)
			{
				//cout<<"after selecting"<<a<<"m is "<<m<<"\n";
				if(a!=sel)
				cnt++;
				a=a-sel;
				m=m-1;
				//cout <<"vectior is";op(v);
			}
			x++;
		}
		return cnt;
	}
	return -1;
}
void solve() 
{
	ll n,m;
	cin>>n>>m;
	ip(ll);
	sort(all(vec));
	//op(vec)
	cout<<rsolve(vec,m);
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
