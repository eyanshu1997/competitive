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
#define R 3 
#define C 3
using namespace std;
int minCost(int cost[R][C], int m, int n) 
{ 
     int i, j; 
  
     // Instead of following line, we can use int tc[m+1][n+1] or  
     // dynamically allocate memory to save space. The following line is 
     // used to keep the program simple and make it working on all compilers. 
     int tc[R][C];   
  
     tc[0][0] = cost[0][0]; 
  
     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++) 
        tc[i][0] = tc[i-1][0] + cost[i][0]; 
  
     /* Initialize first row of tc array */
     for (j = 1; j <= n; j++) 
        tc[0][j] = tc[0][j-1] + cost[0][j]; 
  
     /* Construct rest of the tc array */
     for (i = 1; i <= m; i++) 
        for (j = 1; j <= n; j++) 
            tc[i][j] = min(tc[i-1][j-1], min(
                           tc[i-1][j],  
                           tc[i][j-1])) + cost[i][j]; 
  
     return tc[m][n]; 
}
int main() 
{ 
   int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
   printf(" %d ", minCost(cost, 2, 2)); 
   return 0; 
} 
