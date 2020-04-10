#include <bits/stdc++.h>
using namespace std;
int getvalue(char a)
{
	int x=a-'0';
	if(x>=0&&x<=9)
		return x;
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	for(int p=0;p<num;p++)
	{
		string n;
		cin>>n;
		int open=0;
		vector <char> a;
		for(int i=0;i<n.size();i++)
		{
			int x=getvalue(n[i]);
			//cout<<"open is "<<open<<" x is "<<x<<"\n";
			if(x>open)
			{
				int diff=x-open;
				for(int j=0;j<diff;j++)
				{
					open++;
					a.push_back('(');
				}
				a.push_back(n[i]);
			}
			else
				if(x<open)
				{
					int diff=open-x;
					for(int j=0;j<diff;j++)
					{
						open--;
						a.push_back(')');
					}
					a.push_back(n[i]);
				}
				else
					a.push_back(n[i]);
		}
		//cout<<"open is "<<open<"\n";
		while(open--)
			a.push_back(')');
		cout<<"CASE #"<<p+1<<": ";
		for(int i=0;i<a.size();i++)
			cout<<a[i];
		cout<<"\n";
	}
}
