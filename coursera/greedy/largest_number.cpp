#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
bool cmp(string a,string b)
{
	int i=0;
	string ab=a+b;
	string ba=b+a;
	while(i<ab.size())
	{
		if(ab[i]==ba[i])
			i++;
		else
			if(ab[i]<ba[i])
				return false;
			else
				return true;
	}
	return false;
}

string largest_number(vector<string> a) {
  sort(a.begin(),a.end(),cmp);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
