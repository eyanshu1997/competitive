#include <bits/stdc++.h>
#define ll long long int
#define tr(a,x) for(auto a:x)
#define tri(a,x) for(auto a=x.begin();a!=x.end();a++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define fo(i,x) for(int i=0;i<x;i++)
#define p_b(x,i) x.push_back(i)
#define printe(i) cout<<i<<" "
#define ip(s) vector <s>vec;for(int i=0;i<n;i++){s tmp;cin>>tmp;vec.push_back(tmp);}
using namespace std;
bool cmp(string a,string b)
{
return sz(a)>sz(b);
}
string merge(string s1,string s2)
{
	cout<<"solving "<<s1<<" "<<s2<< "\n";
	int f1=s1.find('*');
	int f2=s2.find('*');
	string s12=s1.substr(f1+1,sz(s1));
	string s11=s1.substr(0,f1);
	string s22=s2.substr(f2+1,sz(s2));
	string s21=s2.substr(0,f2);
	string ri,le;
	if(sz(s22)<=sz(s12))
	{
		cout<<"case 1 "<<s22<<" "<<s12<<"\n";
		if(sz(s22)==0)
			ri=s12;
		else
		{		
			if(s12.find(s22)==string::npos)
				return "*";
			else 
				ri= s12;
		}
	}
	else
	{
		//cout<<"case 2\n";
		if(sz(s12)==0)
		{	
			ri=s22;
		}		
		else
		{
			if(s22.find(s12)==string::npos)
				return "*";
			else 
				ri= s22;
		}
	}
	if(sz(s21)<=sz(s11))
	{
		cout<<"case 3\n";
		if(sz(s21)==0)
			le=s11;
		else
		{		
			if(s11.find(s21)==string::npos)
				return "*";
			else 
				le= s11;
		}
	}
	else
	{
		cout<<"case 4\n";
		if(sz(s11)==0)
			le=s21;
		else
		{
			if(s21.find(s11)==string::npos)
				return "*";
			else 
				le= s22;
		}
	}
	cout<<"right is "<<ri<<" left is "<<le<<"\n";
	return le+"*"+ri;
}
void rsolve(vector <string> v)
{
	sort(all(v),cmp);
	auto i=v.at(0);
	tr(a,v)
	{
		//cout<<"\nusing "<<a<<" ";
		i=merge(i,a);
		if(i=="*")
			break;
		//printe(i);
	}
	if(i=="*")
		cout<<i;
	else
	{
		int f1=i.find('*');
		cout<<i.substr(0,f1)+i.substr(f1+1,sz(i));
	}
}
void solve() 
{
	int n;
	cin>>n;
	ip(string);
	rsolve(vec);
}

int main()
{

	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	fo(i,num)
	{
    		cout << "Case #" << i << ": ";
    		solve();
		cout<<"\n";
	}
}
