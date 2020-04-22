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
using namespace std;


ll eval(ll a, ll b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
cout<<"error\n";
	cout<<"op is"<<op<<"\n";
    assert(0);
  }
}
pp maxandmin(vector<vi> MI,vector<vi> MA,vector<char>OP,int i,int j)
{
	ll ma=INT_MIN,mi=INT_MAX,a,b,c,d;
	for(int k=i;k<j;k++)
	{
		//cout<<"op k is<<"<<OP[k-1]<<" "<<k-1<<"\n";
		a=eval(MI[i][k],MI[k+1][j],OP[k]);
		b=eval(MI[i][k],MA[k+1][j],OP[k]);
		c=eval(MA[i][k],MI[k+1][j],OP[k]);
		d=eval(MA[i][k],MA[k+1][j],OP[k]);
		mi=min(mi,min(a,min(b,min(c,d))));
		ma=max(ma,max(a,max(b,max(c,d))));
	}
	return make_pair(mi,ma);
}
void parse(string exp,vector<char> &c,vi &d)
{
	for(int i=0;i<sz(exp);i++)
	if(exp[i]=='*'||exp[i]=='+'||exp[i]=='-')
		p_b(c,exp[i]);
	else
		p_b(d,stoll(exp.substr(i,1)));
}
int get_max(string &exp)
{
	vector<char> c;vi d;
	parse(exp,c,d);
	//op(d);
	vector<vi>MI(sz(d),vi(sz(d),INT_MAX));
	vector<vi>MA(sz(d),vi(sz(d),INT_MIN));
	for(int i=0;i<sz(d);i++)
		{MI[i][i]=d[i];MA[i][i]=d[i];}
	for(int s=0;s<sz(d)-1;s++)
		for(int i=0;i<sz(d)-s-1;i++)
		{
			int j=i+s+1;
			pp res=maxandmin(MI,MA,c,i,j);
			MA[i][j]=res.second;
			MI[i][j]=res.first;
		}
	/*tr(a,MA)
	{
		op(a);newl;
	}*/
	return MA[0][sz(d)-1];
}


int main() {
  string s;
  std::cin >> s;
  std::cout << get_max(s) << '\n';
}
