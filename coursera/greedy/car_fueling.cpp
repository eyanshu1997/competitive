#include <iostream>
#include <vector>
#include<bits/stdc++.h>	
using namespace std;
void print(vector <int> s)
{
	//cout<<"size is "<<s.size()<<"\n";
	for(auto i=s.begin();i<s.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<"\n";
}
int compute_min_refills(int m, vector<int> stops) 
{
	//print(stops);
	if((*(stops.end()-1)-*(stops.begin()))<=m)
	{
		//cout<<*(stops.end()-1)<<" "<<*stops.begin()<<" "<<(*(stops.end())-*(stops.begin()))<<" "<<((*(stops.end())-*(stops.begin()))<=m)<<"\n";
		return 0;
	}
	if(*(stops.begin()+1)-*(stops.begin())>m)
		return -1;
    	int x=*stops.begin();
	x=x+m;
	vector<int>::iterator i;
	for(i=stops.begin();i!=stops.end();i++)
		if(*i>x)
		{
			i--;
			break;
		}
	//cout<<"selected stop is "<<*i<<"\n";
	vector <int>stop;
	copy(i,stops.end(),back_inserter(stop));
	int y=compute_min_refills(m,stop);
	if(y==-1)
		return -1;
	else
		return 1+y;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;
	vector<int> stops;
	stops.push_back(0);
	//print(stops);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >>tmp;
		stops.push_back(tmp);
	}
	stops.push_back(d);
    
    cout << compute_min_refills(m, stops) << "\n";

    return 0;
}
