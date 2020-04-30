#include <iostream>
#include<bits/stdc++.h>
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci(int n) {
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

int main() {
    int n;
    std::cin >> n;
   // assert( get_fibonacci_last_digit_naive(n)==get_fibonacci(n));
    std::cout << get_fibonacci(n) << '\n';
    }
