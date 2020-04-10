#include <iostream>
#include<bits/stdc++.h>
#define ulli unsigned long long int

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
ulli fibonacci_sum(ulli n)
{
	n=n%60;
	ulli prev=0,curr=1;
	for(int i=2;i<=n+2;i++)
	{
		ulli tmp=prev;
		prev=curr;
		curr=(tmp+prev)%10;
	}
	if(curr==0)
		return 9;
	else
		return curr-1;
}
int main() {
    long long n = 0;
    std::cin >> n;
    //assert(fibonacci_sum_naive(n)==fibonacci_sum(n));
    std::cout << fibonacci_sum(n)<<"\n";
}
