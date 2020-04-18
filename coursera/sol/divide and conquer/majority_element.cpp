#include <algorithm>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int maj(vector <int>&a,int left, int right)
{
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int mid=(left+right)/2;
  int le=maj(a,left,mid);
  int ri=maj(a,mid,right);
 //  cout<<" returned "<<left<<" "<<right<<"\n";
//  cout<<"le "<<le<<" re "<<ri <<"\n";
  if(ri==le)
	return ri;
  int le_c=0,re_c=0;
  for(int i=left;i<right;i++)
  {	if(a[i]==le)
		le_c++;
	if(a[i]==ri)
		re_c++;
  }
 // cout<<"le Le_c is: "<<le<<" "<<le_c<<" re re_c is: "<<ri<<" "<<re_c<<"\n";
  if(le_c>re_c)
	return le;
  if(re_c>le_c)
	return ri;
}
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int mid=(left+right)/2;
  int le=maj(a,left,mid);
  int ri=maj(a,mid,right);
  int le_c=0,re_c=0;
  if(ri==le)
  {
	  for(int i=left;i<right;i++)
	  {	
		if(a[i]==ri)
			re_c++;
	  }
  //cout<<" re re_c is: "<<ri<<" "<<re_c<<" "<<((right/2)+1)<<"\n";
	  if(re_c>(right/2))
		return ri;
  }
  re_c=0;
  for(int i=left;i<right;i++)
  {	if(a[i]==le)
		le_c++;
	if(a[i]==ri)
		re_c++;
  }
  //cout<<"le Le_c is: "<<le<<" "<<le_c<<" re re_c is: "<<ri<<" "<<re_c<<" c is "<<(right/2)<<"\n";
  if(le_c>(right/2))
	return le;
  if(re_c>(right/2))
	return ri;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
