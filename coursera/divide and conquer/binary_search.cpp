#include <iostream>
#include <cassert>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &a, int x,int left ,int right) {
  //cout<<"right "<<right <<" left "<< left<<"\n"; 
  if (left > right) return -1;
  //write your code here
  int mid=(left+right)/2;
  if(a[mid]==x)
	return mid;
   else
	if(a[mid]>x)
		return binary_search(a,x,left,mid-1);
	else
		return binary_search(a,x,mid+1,right);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
 // sort(a.begin(),a.end());
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i],0,n-1) << ' ';
  }
}
