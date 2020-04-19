#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>


int main() {
    int n;
    std::cin >> n;
    std::vector<long long int> numbers(n);
    long int  max = INT_MIN+1;
    long int smax=INT_MIN;
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
	if(smax<numbers[i])
	{
		if(max<numbers[i])
		{
			smax=max;
			max=numbers[i];
		}		
		else
			smax=numbers[i];
	}
    }
    std::cout << max*smax << "\n";
    return 0;
}
