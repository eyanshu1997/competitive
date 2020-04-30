#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#define ulli unsigned long long int
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
int fibonacci_sum(ulli n)
{
	n=n%60;
	if(n<=1)
		return n;
	int prev=0,curr=1;
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
int fibonacci_sum_partial(ulli from,ulli to)
{
	int x;
	if(from>0)
		x=fibonacci_sum(from-1);
	else
		x=0;
	int y=fibonacci_sum(to);
//	std::cout<<x<<" "<<y<<"\n";
	if(x>y)
	{
		y=y+10;
	}
	return y-x;
}
int main() {
    long long from, to;
    std::cin >> from >> to;
	//assert(get_fibonacci_partial_sum_naive(from, to)==fibonacci_sum_partial(from, to));
    std::cout <<  fibonacci_sum_partial(from, to)<< '\n';
}
