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
using namespace std;
string parse(string s)
{
	string str="";
	string tmp="";
	for(int i=0;i<s.size();i++)
	{
		if(!isdigit(s[i]))
			tmp.push_back(s[i]);
		else
		{
			int x=0;
			str=str+tmp;
			tmp="";
			string t="";
			while(s[i]!='(')
			{
				x=x*10+((int)(s[i]-'0'));
				i++;
			}
			i++;
			int count=1;int c=1;
			while(count!=0)
			{
				if(s[i]==')')
				{
					count--;
					
				}
				else
					if(s[i]=='(')
					{
						count++;c++;}
				if(count==0)
					break;
				t.push_back(s[i]);
				i++;
			}
			//cout<<"checking for " <<t<<"\n";
			//t.pop_back();
			string tm=parse(t);
			//cout<<"tm is "<<tm<<"\n";
			fo(j,x)
				tmp=tmp+tm;
			str=str+tmp;
			tmp="";
		}
	}
	if(tmp!="")
		str=str+tmp;
	return str;
}
pp res(string a)
{
	int i=1,j=1;
	tr(x,a)
	{
		switch(x)
		{
			case 'W':	j=j-1;
					while(j<1)
						j=j+1000000000;
					if(j>1000000000)
						j=j%1000000000;
					break;
			case 'N':	i=i-1;
					while(i<1)
						i=i+1000000000;
					if(i>1000000000)
						i=i%1000000000;
					break;
			case 'E':	j=j+1;
					while(j<1)
						j=j+1000000000;
					if(j>1000000000)
						j=j%1000000000;
					break;
			case 'S':	i=i+1;
					while(i<1)
						i=i+1000000000;
					if(i>1000000000)
						i=i%1000000000;
					break;
		}
	}
	return make_pair(j,i);
}
void rsolve(string s)
{
	string str=parse(s);
	pp j=res(str);
	cout<<j.first<<" "<<j.second;	
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
    		cout << "Case #" << i << ": ";
    		solve();
		cout<<"\n";
	}
}
