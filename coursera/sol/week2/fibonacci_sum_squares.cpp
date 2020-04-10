#include <iostream>
#include<bits/stdc++.h>
#define ulli unsigned long long int
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int get_fibonacci(ulli n) {
	n=n%60;
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous%10;
        previous = current%10;
        current = tmp_previous + current;
    }

    return current % 10;
}
int fibonacci_sum_squares(ulli n)
{
//std::	cout<<get_fibonacci(n)<<" "<<get_fibonacci(n+1)<<"\n";
	return (get_fibonacci(n)*get_fibonacci(n+1))%10;
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n)<<"\n";
}
