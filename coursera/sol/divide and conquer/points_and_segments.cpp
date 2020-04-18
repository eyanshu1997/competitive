#include <iostream>
#include <vector>
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
#define vpp vector<pair<int,int>>
#define ip(s) vector <s>vec;for(int i=0;i<n;i++){s tmp;cin>>tmp;vec.push_back(tmp);}
#define vi vector<int>
using namespace std;
bool cmp(pp a,pp b)
{return a.second<b.second;
}
vector<int> fast_count_segme(vector<int> starts,vector<int> ends, vector<int> points) 
{
	 // cout<<"points size "<<starts.size()<<"\n"<<ends.size()<<"\n";
	vector<int> cnt(points.size(),0);
	sort(all(starts));
	sort(all(ends));
	fo(a,points.size())
	{
		int i,j;
		auto ix=lower_bound(all(starts),points[a]);
		if(ix==starts.end())
			i=starts.size();		
		else
		{		
			i=int(ix-starts.begin());
			int iv=starts[i];
			while(starts[i]==points[a])
			{i++;
			}
		}
		auto jx=lower_bound(all(ends),points[a]);
		if(jx==ends.end())
			j=ends.size();
		else	
		{	
			j=int(jx-ends.begin());
			int ij=ends[j];
			//j--;
		}
		//cout<<i<<" "<<j<<"\n";	
		cnt[a]=i-j;
	}	
	return cnt;
}
/*
vector<int> fast_count_segments(vpp seg, vpp points) 
{
	 // cout<<"points size "<<starts.size()<<"\n"<<ends.size()<<"\n";
	vector<int> cnt(points.size(),0);
	sort(all(seg));
	fo(a,points.size())
	{
		int i,j;
		auto ix=lower_bound(all(seg),make_pair(points[a],0));
		if(ix==starts.end())
			cnt[a]=0;		
		else
		{
			while((*ix).first==points[a])
				ix--;
			vpp tmp;
			tmp.assign(ix,seg.end());
			sort(all(tmp),cmp);
			auto ij=lower_bound(all(tmp),make_pair(0,points[a]),cmp);
			while(ij->second==points[a]&&ij!=tmp.end())
				ij++;
			cnt[a]=ix-tmp.begin();
		}
	}	
	return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}
*/
int main() {
  int n, m;
  std::cin >> n >> m;
  //vector<pp> seg;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
//seg.push_back(make_pair(starts[i],ends[i]));
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt=fast_count_segme(starts ,ends, points);
  //vector<int> cnt=fast_count_segments(seg, points);
  for (size_t i = 0; i < cnt.size(); i++) {
   std::cout << cnt[i] << ' ';
  }
}

