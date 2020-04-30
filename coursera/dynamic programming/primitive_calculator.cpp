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
vpp solve(int m,vi act)
{
	vpp dp(m+1,make_pair(INT_MAX,0));
	dp[0].first=0;
	for(int i=1;i<=m;i++)
	{
		tr(a,act)
		{
			int n=INT_MAX,prev=0;
			if(i>=a)
			{
				switch(a)
				{
					case 1: prev=i-a;
						n=(dp[prev].first)+1;
						//cout<<"for money "<<i<<" coin "<<a<<" n is "<<n<<" prev is"<<prev;newl;
						//cout<<"n is"<<n;newl;
						if(n<dp[i].first)
						{
							dp[i].first=n;
							dp[i].second=prev;
						}
						break;
					case 2: if(i%2==0)
						{
							prev=i/2;
							n=(dp[prev].first)+1;
							//cout<<"for money "<<i<<" coin "<<a<<" n is "<<n<<" prev is"<<prev;newl;
							//cout<<"n is"<<n;newl;
							if(n<dp[i].first)
							{
								dp[i].first=n;
								dp[i].second=prev;
							}
						}
						break;
					case 3: if(i%3==0)
						{
							prev=i/3;
							n=(dp[prev].first)+1;
							//cout<<"for money "<<i<<" coin "<<a<<" n is "<<n<<" prev is"<<prev;newl;
							//cout<<"n is"<<n;newl;
							if(n<dp[i].first)
							{
								dp[i].first=n;
								dp[i].second=prev;
							}
						}
						break;
					default:
						cout<<"wrong deno"<<endl;
						break;
				}
			}
		}
	}
	//cout<<"dp array is";	
	//for(int i=0;i<dp.size();i++)
	//cout<<i<<" "<<dp[i].first<<"  "<<dp[i].second<<"\n";
	return dp;
}
vi sol(int n)
{
	vi act,seq;
	p_b(act,1);
	p_b(act,2);
	p_b(act,3);
	vpp tmp=solve(n,act);
	int i=n;
	while(i!=0)
	{
		p_b(seq,i);
		i=tmp[i].second;
	}
	//p_b(seq,0);
	reverse(seq.begin(),seq.end());
	return seq;
}
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = sol(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
