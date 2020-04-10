#include <iostream>
using namespace std;
int get_change(int m) {
	int n=0;
	n=n+(m/10);
	//cout<<m/10<<" ";
	m=m%10;
	n=n+(m/5);
	//cout<<m/5<<" ";
	m=m%5;
	//cout<<m<<"\n";
	n=n+m;
	return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
