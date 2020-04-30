#include <bits/stdc++.h>
#define ll long long int
#define tr(a,x) for(auto a:x)
#define tri(a,x) for(auto a=x.begin();a!=x.end();a++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define fo(i,x) for(int i=0;i<x;i++)
#define p_b(x,i) x.push_back(i)
#define printe(i) cout<<i<<"\n"
#define ip(s) vector <s>vec;for(int i=0;i<n;i++){s tmp;cin>>tmp;vec.push_back(tmp);}
using namespace std;
bool cmp(string a,string b)
{
return sz(a)>sz(b);
}
int check(string i,string b)
{
	int s=i.find('*');
	i=i.erase(s,1);
	s=b.find('*');
	b=b.erase(s,1);
	//cout<<i<<" "<<b<<"\n";
	if(sz(i)<sz(b))
		return i.find(b);
	else
		return b.find(i);
}
string merge(string s1,string s2)
{
	//cout<<"solving "<<s1<<" "<<s2<< "\n";
	int f1=s1.find('*');
	int f2=s2.find('*');
	vector<string> s;
	string tmp;	
	if(f1==0||f1==sz(s1)-1)
	{
		//cout<<s1<<"\n";
		p_b(s,s1);
	}
	else
	{
		tmp=s1.substr(f1,sz(s1));
		//cout<<tmp<<"\n";
		p_b(s,tmp);
		tmp=s1.substr(0,f1+1);
		//cout<<tmp<<"\n";
		p_b(s,tmp);
	}
	if(f2==0||f2==sz(s2)-1)
	{
		p_b(s,s2);
	}
	else
	{
		tmp=s2.substr(f2,sz(s2));
		//cout<<tmp<<"\n";
		p_b(s,tmp);
		tmp=s2.substr(0,f2+1);
		//cout<<tmp<<"\n";
		p_b(s,tmp);
	}
	sort(all(s),cmp);
	auto i=s.at(0);
	//cout<<"here \n";
	tr(a,s)
	{
		//cout<<a<<"\n";
		if(check(i,a)!=string::npos)
		{
			//cout<<"not found";
		}
	}
	return "heello";
}
void rsolve(vector <string> v)
{
	sort(all(v),cmp);
	auto i=v.at(0);
	tr(a,v)
	{
		//cout<<"\nusing "<<a<<" ";
		//i=merge(i,a);
		merge(i,a);		
		if(i=="*")
			break;
		//printe(i);
	}
	/*
	if(i=="*")
		cout<<i;
	else
	{
		int f1=i.find('*');
		cout<<i.substr(0,f1)+i.substr(f1+1,sz(i));
	}
*/
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
