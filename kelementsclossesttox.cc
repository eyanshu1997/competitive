#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	//code
	int num;
	cin>>num;
	while(num--)
	{
	    vector<int> a;
	    int n;
	    cin>>n;
	    //int *a=(int *)malloc(n*sizeof(int));
	    for(int i=0;i<n;i++)
	    {
	        int t;
	        cin>>t;
	        a.push_back(t);
	    }
	    int k,x;
	    cin>>x>>k;
	    auto y=lower_bound(a.begin(),a.end(),k);
          // cout<<*y;
	    //cout<<"\n";
	    //cout<<"\n";
	    //for(auto i=a.begin;i!=a.end())
	    int i=0;
	    if(y-x/2<a.begin())
	    {
	        //cout<<"case 1"<<"\n";
	        auto m=a.begin();
	        while(m!=y)
	        {
	            cout<<*m<<" ";
	            i++;
	            m=m+1;
	        }
	        m=y;
	        while(i<x)
	        {
	            m=m+1;
	            cout<<*m<<" ";
	            i++;
	        }
	    }
	    else
	    {
	        //cout<<"y +x/2 is "<<y+(x/2)<<"  "<<a.end()-1<<"\n";
	        if(y+(x/2)>=a.end())
    	    {
    	       // cout<<"case 2"<<"\n";
    	        int f=(a.end()-y)-1;
    	        auto m=(y-(x-f));
    	       // cout<<"printing values from "<<f<<"   "<<*m<<"\n";
    	        //return 0;
    	        while(m!=y)
    	        {
    	             cout<<*m<<" ";
    	             m=m+1;
    	        }
                m=y;
    	        while(m<a.end()-1)
    	        {
    	            m=m+1;
    	            cout<<*m<<" ";
    	        }
    	    }
    	    else
    	    {
    	        //cout<<"case 3"<<"\n";
    	        auto m=(y-(x/2));
    	        while(m!=y)
    	        {
    	             cout<<*m<<" ";
    	             m=m+1;
    	        }
                m=y;
    	        while(i<x/2)
    	        {
    	            m=m+1;
    	            cout<<*m<<" ";
    	            i++;
    	        }
    	    }
	    }
	    cout<<"\n";
	}
	return 0;
}
