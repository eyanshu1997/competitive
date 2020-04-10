#include <bits/stdc++.h>
using namespace std;
int getvalue(char a)
{
	int x=a-'0';
	if(x>=0&&x<=9)
		return x;
	return -1	;
}

class ip
{
	public:
	char x;
	int remain;
	ip(char a)
	{
		x=a;
		remain=getvalue(a);
	}
};

void print(vector<ip> a)
{
	cout<<"\n------------------------\nthe vector is \n";
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i].x<<" =>> "<<a[i].remain<<"\n";
	}
	cout<<"\n\n";
}
bool cmp(ip a,ip b)
{
	return a.remain>b.remain;
}
void solve(vector<ip> a)
{
	vector<ip>::iterator low,high;
	low=min_element(a.begin(),a.end(),cmp);
	high=max_element(a.begin(),a.end(),cmp);
	cout<<"lowest is "<<to_string((*low).remain)<<"\n";
	cout<<"highest is "<<to_string((*high).remain)<<"\n";
	while((*high).remain!=0)
	{
		;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	for(int p=0;p<num;p++)
	{
		string str;
		cin>>str;
		vector <char> arr;
		int open=0;
		for (unsigned i=0; i<str.length(); ++i)
  		{
			//ip *tmp=new ip(str[i]);
    			arr.push_back(*tmp);
  		}
		print(arr);
		solve(arr);
	}
}
