#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
class knap
{
	public:
	double value;
	double weight;
	double rat;
	knap(double w,double v)
	{
		weight=w;
		value=v;
		rat=w/v;
	}
	void print()
	{
		cout<<value<<" =>>"<<weight<<"  "<<rat<<" ";
	}
};

bool cmp(knap a,knap b)
{ return a.rat<b.rat;}
double get_optimal_value(int cap, vector<knap> k) 
{
	double value = 0.0;
	sort(k.begin(),k.end(),cmp);
	int i=0;
	while(cap>0&&i<=k.size())
	{
		knap l=k[i];
		if(l.weight<cap)
		{
			//l.print();
			cap=cap-l.weight;
			//cout<<l.value<<"\n";
			value=value+l.value;
		}
		else
		{
			//cout<< "case 1\n";
			//l.print();
			//cout<<(l.value*(cap/l.weight))<<"\n";
			value=value+(l.value*(cap/l.weight));
			cap=0;
		}
		i++;
	}
	//cout<<"\n";
	
	return value;
}

int main() {
	int n;
	double capacity,w,v;
	cin >> n >> capacity;
	vector<knap> k;
	for (int i = 0; i < n; i++) 
	{
	    	cin >> v >> w;
		knap *tmp=new knap(w,v);
		k.push_back(*tmp);
	}

	double optimal_value = get_optimal_value(capacity,k);

	cout.precision(10);
	cout << optimal_value << std::endl;
	return 0;
}
