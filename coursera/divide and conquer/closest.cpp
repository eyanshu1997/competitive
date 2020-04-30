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
using namespace std;
bool cmp(pp a,pp b)
{ return a.second<b.second;}
double dist(pp a,pp b)
{
	ll l=abs(a.first-b.first);
	ll r=abs(a.second-b.second);
	ll ls=l*l;
	ll rs=r*r;
	ll re=ls+rs;
	return sqrtl(re);
}
double min(double a,double b)
{
	if(a<b)
		return a;
	return b;
}
double bf(vpp st)
{
	double min=INT_MAX;
	fo(i,st.size())
		for(int j=i+1;j<st.size();j++)
		{
			double d=dist(st[i],st[j]);
			//cout<<"d is "<<d<<" point "<<" ("<<st[i].first<<","<<st[i].second<<") "<<" and  ("<<st[j].first<<","<<st[j].second<<") "<<"\n";
			if(d<min)
				min=d;
		}
	return min;
}
double minimal_distance(vpp po) {
	sort(all(po));
  //write your code here
	if(sz(po)<=3)
		return bf(po);
	int m=(sz(po)/2);
	pp mid=po[m];
	vector<pp>s1,s2,st;
	tr(a,po)
		if(a.first<mid.first)
			p_b(s1,a);
		else
			p_b(s2,a);
	double d1=minimal_distance(s1);
	double d2=minimal_distance(s2);
	double d=min(d1,d2);
	tr(a,po)
		if(abs(a.first-mid.first)<=d)
			p_b(st,a);
	sort(all(st),cmp);
	return min(d,bf(st));
}

int solve() {
  //test();
	//return 0;
  size_t n;
  std::cin >> n;
  int x,y;
  vpp p;
  for (size_t i = 0; i < n; i++) {
    std::cin >> x>> y;p_b(p,make_pair(x,y));
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(p) << "\n";
}
int main()
{

solve();
}
