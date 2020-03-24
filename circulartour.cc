#include <bits/stdc++.h>
using namespace std;

class petrolpump
{
	public:
	int distance;
	int petrol;
};
int printtour(petrolpump *arr,int n)
{
	int start=0;
	int end=1;
	int curr_petrol=arr[start].petrol-arr[start].distance;
	while(end!=start || curr_petrol<0)
	{
		while(curr_petrol<0&&start!=end)
		{
			curr_petrol-=arr[start].petrol-arr[start].distance;
			start=(start+1)%n;
			if(start ==0)
				return -1;
		}
		curr_petrol+=arr[end].petrol- arr[end].distance;
		end=(end+1)%n;
	}
	return start;
}
int main()
{
	int n;
	cin>>n;
	petrolpump *arr=new petrolpump[n];
	for(int i=0;i<n;i++)
		cin>>arr[i].petrol>>arr[i].distance;
	int start=printtour(arr,n);
	(start == -1)? cout<<"No solution": cout<<"Start = "<<start;  
	return 0;
}
