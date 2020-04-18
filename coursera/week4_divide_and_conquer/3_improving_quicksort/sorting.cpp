#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
#include <bits/stdc++.h>
#define ll long long int
#define tr(a,x) for(auto a:x)
#define tri(a,x) for(auto a=x.begin();a!=x.end();a++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define fo(i,x) for(int i=0;i<x;i++)
#define p_b(x,i) x.push_back(i)
#define printed(x,i) cout<<x<<i<<"\n"
#define printe(i) cout<<i<<" "
#define ip(s) vector <s>vec;for(int i=0;i<n;i++){s tmp;cin>>tmp;vec.push_back(tmp);}
using namespace std;
void print(vector <int>a)
{
	tr(x,a)
	printe(x);
      cout<<"\n";
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
            printed("j is :",j);
printed("i is",i);
      printed("a ","is");
      print(a);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  cout<<"a[l] is ";
  printe(a[l]);
  cout<<" the a is\n";
  print(a);
  printed(" l is ",l);
  printed(" r is ",r);
  int m = partition2(a, l, r);
  cout<<"first :\n";
  print(a);
  printed("part ",m);
  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}