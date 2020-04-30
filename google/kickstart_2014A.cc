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
int min(int a,int b)
{
	return a<b;
}
using namespace std;
vi parse(string s)
{
	vi d;
	int i=0;
	while(i<sz(s))
	{
		int st=i;
		while(s[i]!='-'&&i<sz(s))
		{
			i++;
		}
		p_b(d,stoll(s.substr(st,i)));
		i++;
	}
	return d;
}
void printd(char a)
{
	switch(a)
	{
		case '0': printe("zero");break;
		case '1': printe("one");break;
		case '2': printe("two");break;
		case '3': printe("three");break;
		case '4': printe("four");break;
		case '5': printe("five");break;
		case '6': printe("six");break;
		case '7': printe("seven");break;
		case '8': printe("eight");break;
		case '9': printe("nine");break;

	}
}
void prints(int c)
{
	switch(c)
	{
		case 2: printe("double");break;
		case 3: printe("triple");break;
		case 4: printe("quadruple");break;
		case 5: printe("quintuple");break;
		case 6: printe("sextuple");break;
		case 7: printe("septuple");break;
		case 8: printe("octuple");break;
		case 9: printe("nonuple");break;
		case 10: printe("decuple");break;
	}
}
void rsolve(string s)
{
	//cout<<s<<"\n";//return;
	for(int i=0;i<sz(s);i++)
	{
		int count=1;
		if(i!=sz(s)-1)
		while(s[i+1]==s[i])
		{
			count++;i++;
		}
		if(count>0)
			prints(count);
		printd(s[i]);
		
	}
}
void solve() 
{
	string n;
	cin>>n;
	string s;
	cin>>s;
	vi x=parse(s);
	fo(i,sz(x))
	{
		string tmp=n.substr(0,x[i]);
		rsolve(tmp);
		n.erase(n.begin(),n.begin()+(x[i]));
	}
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
