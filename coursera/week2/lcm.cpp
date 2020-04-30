#include <iostream>
#include<bits/stdc++.h>
#define ulli unsigned long long int
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
ulli gcd(ulli a,ulli b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
ulli lcm(ulli a,ulli b)
{
	ulli g=gcd(a,b);
	return (a*b)/g;
}
int main() {
  int a, b;
  std::cin >> a >> b;
  //assert(lcm_naive(a,b)==lcm(a,b));
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
