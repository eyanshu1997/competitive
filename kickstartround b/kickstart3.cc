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
class counto
{
public:ll s,w,n,e;
counto(ll a,ll b,ll c,ll d)
{
	n=a,w=b;e=c;s=d;

}
};
using namespace std;
counto parse(string str)
{
	ll n=0,w=0,e=0,s=0;
	for(int i=0;i<str.size();i++)
	{
		if(!isdigit(str[i]))
		{
			switch(str[i])
			{
				case 'W':	w++;
						break;
				case 'N':	n++;
						break;
				case 'E':	e++;
						break;
				case 'S':	s++;
						break;
			}
		}
		else
		{
			int x=0;
			string t="";
			while(str[i]!='(')
			{
				x=x*10+((int)(str[i]-'0'));
				i++;
			}
			i++;
			int count=1;int c=1;
			while(count!=0)
			{
				if(str[i]==')')
				{
					count--;
					
				}
				else
					if(str[i]=='(')
					{
						count++;c++;}
				if(count==0)
					break;
				t.push_back(str[i]);
				i++;
			}
			//cout<<"checking for " <<t<<"\n";
			//t.pop_back();
			counto tm=parse(t);
			//cout<<"tm is "<<tm<<"\n";
			s=s+x*tm.s;
			w=w+x*tm.w;
			e=e+x*tm.e;
			n=n+x*tm.n;
		}
	}
	counto *x=new counto(n,w,e,s);
	return *x;
}
void rsolve(string s)
{
	counto cnt=parse(s);
	ll j=1,i=1;
	j=(j-cnt.n)+cnt.s;
	i=(i-cnt.w)+cnt.e;
	//cout<<"my check"<<-5/2<<"\n";
	if(j<1)
	{
		j=abs(j)%1000000000;
		j=1000000000-j;
	}
	if(j>1000000000)
		j=j%1000000000;
	if(i<1)
	{
		i=abs(i)%1000000000;
		i=1000000000-i;
	}
	if(i>1000000000)
		i=i%1000000000;
	cout<<i<<" "<<j;	
}
void solve() 
{
	string s;
	cin>>s;
	rsolve(s);
}

int main()
{

	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	fo(i,num)
	{
    		cout << "Case #" << i +1<< ": ";
    		solve();
		cout<<"\n";
	}
}
