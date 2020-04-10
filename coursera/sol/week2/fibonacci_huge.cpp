#include <iostream>
#include<bits/stdc++.h>
#define ulli unsigned long long int

ulli find_period(ulli m)
{
	if(m==1)
return 1;
	ulli a = 0, b = 1, c = a + b;
    for (ulli i = 0; i < m * m; i++) 
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) 
		return i + 1;
    }
    return 0;
}
ulli get_fibonacci(ulli n,ulli m)
{
	if(n<=1)
		return n;
	ulli x=find_period(m);
	n=n%x;
	//std::cout<<"period is "<<x<<" n is "<<n<<"\n";
	if(n<=1)
		return n;
	ulli prev=0;
	ulli curr=1;
	for (ulli i = 0; i < n - 1; ++i) 
	{
		ulli tmp = prev;
		prev = curr;
		curr = (tmp + curr)%m;
    	}
	//std::cout<<"fibo is "<<curr<<"\n";
    	return curr;
}
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    ulli n, m;
    std::cin >> n >> m;
    //assert(get_fibonacci_huge_naive(n,m)==get_fibonacci(n,m));
    std::cout << get_fibonacci(n,m) << '\n';
 //std::cout << find_period(m) << '\n';
    //std::cout << get_fibonacci_huge_naive(n,m) << '\n';
}
