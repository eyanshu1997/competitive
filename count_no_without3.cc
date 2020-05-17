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
int rsolve(int n)
{
    //cout<<"for n "<<n<<"\n";
    if(n<3)
        return n;
    if(n<10)
        return n-1;
    int x=n;
    int d=1;
    while(x>9)
    {
        d++;
        x=x/10;
    }
    int msb=n/(pow(10,d-1));
    int di=pow(10,d-1);int a,b,c;
    if(msb==3)
    {
	a=3*rsolve(di-1);
	b=2;
	c=0;
    }
    else
    {
	    c=rsolve(n%(msb*di));
	    if(msb>2)
	    {
		msb--;
	    }
	    a=msb*rsolve(di-1);
	    b=msb;
    }
    //cout<<"a is "<<a<<" b is "<<b<<" c is "<<c <<"\n";// return 1;
    int res=a+b+c;
    //cout<<"for n "<<n <<" res is "<<res<<"\n";
    return res;
}
void solve() 
{
	int n;
	cin>>n;
	cout<<rsolve(n);
}

int main()
{

	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	fo(i,num)
	{
		solve();
		cout<<"\n";
	}
}
