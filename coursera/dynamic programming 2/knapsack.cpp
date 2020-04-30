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
using namespace std;


using std::vector;
int knapsack(int W,vi &w)
{
	vector<vi> knap(sz(w)+1,vi(W+1,INT_MAX));
	fo(i,sz(w)+1)
		knap[i][0]=0;
	fo(i,W+1)
		knap[0][i]=0;
	for(int j=1;j<W+1;j++)
		for(int i=1;i<sz(w)+1;i++)
		{
			knap[i][j]=knap[i-1][j];
			if(w[i-1]<=j)
			{
				int val=knap[i-1][j-w[i-1]]+w[i-1];
				if(knap[i][j]<val)
					knap[i][j]=val;
			}
			//cout<<"i "<<i<<" j "<<j<<" "<<knap[i][j]<<"\n";
		}
	/*
	fo(i,sz(w)+1)
	{
		fo(j,W)
		{
			printe(knap[i][j]);
		}
		newl;
	}
	newl;*/
	return knap[sz(w)][W];
}
int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << knapsack(W, w) << '\n';
}
