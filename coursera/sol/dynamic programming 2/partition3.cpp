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

#include <iostream>
#include <vector>

using std::vector;


int partition3(vector <int> &A)  
{  
	int sum = 0;  
	int i, j;  
	tr(a,A)  
	sum += a;  
	if(sz(A)<3)
	return 0;
	if (sum % 3 != 0)  
	return 0;  

	vector<vi> part(sum / 3 + 1,vi(sz(A) + 1,0));
	int count=0;
	for (i = 1; i < sz(part); i++)  
	{  
		for (j = 1; j < sz(part[0]); j++)  
		{  
			part[i][j] = part[i][j - 1];  
			if (i >= A[j - 1]) 
			{
				ll tmp=part[i-A[j-1]][j-1]+A[j-1];
				if(tmp>part[i][j])
					part[i][j]=tmp;
				if(part[i][j]==sum/3)
					count+=1;
			}
		}      
	}    
	if(count<3)
		return 0; 
	return 1;  
}  
  

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
