#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define tr(a,x) for(auto a:x)
#define tri(a,x) for(auto a=x.begin();a!=x.end();a++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define fo(i,x) for(int i=0;i<x;i++)
#define p_b(x,i) x.push_back(i)
#define printe(i) cout<<i<<" "
#define printed(x,i) cout<< x  <<i<<"\n"
#define ip(s) vector <s>vec;for(int i=0;i<n;i++){s tmp;cin>>tmp;vec.push_back(tmp);}
using namespace std;

using std::vector;
long long merge(vector <int > &a,ll l ,ll mid ,ll r)
{
	//cout<<"before merge\n";
	//for(int i=l;i<=r;i++)
	//	cout<<a[i]<<" ";
	//cout<<"\n";
	int i=0,j=0,k=l,n1=mid-l+1,n2=r-mid;
	long long count=0;
	vector<int>la,ra;
	fo(p,n1)
		p_b(la,a[l+p]);
	fo(p,n2)
		p_b(ra,a[mid+p+1]);
	while(i<n1&&j<n2)
	{
		if(la[i]<=ra[j])
		{
			a[k++]=la[i++];
		}
		else
		{count+=(n1-i);
			//cout<<"increasing count for "<<la[i]<<" "<<ra[j]<<" j is "<<j<<"\n";
			a[k++]=ra[j++];
		}
	}
	while(i<n1)
	{
		//cout<<"remaining "<<la[i]<<"\n";
		//count+=n2;
		a[k++]=la[i++];
	}
	
	while(j<n2){
		a[k++]=ra[j++];}
	return count;
}
long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {

  long long number_of_inversions = 0;
  if (left<right)
  {
	size_t ave =  (right +left) / 2;
	ll l = get_number_of_inversions(a,  left, ave);
	ll r = get_number_of_inversions(a, ave+1, right);
	//printed("left ",left); printed(" ",ave);printed(" ",l);printed(" right ",ave+1);printed(" ",right);printed(" ",r);
	//cout<<"\n";
	number_of_inversions=number_of_inversions+l+r;
	ll m=merge(a,left,ave,right);
	//cout<<"after merge\n";
	//for(int i=left;i<=right;i++)
	//	cout<<a[i]<<" ";
	//cout<<"\n";
	//printed("merge ",m);cout<<"\n";
	number_of_inversions+=m;
  }
  return number_of_inversions;
}
int naive(vector <int >a)
{
int count=0;
//tr(x,a)
//printe(x);
//cout<<"\n";
fo(i,a.size()-1)
	for(int j=i+1;j<a.size();j++)
		if(a[i]>a[j])
		{//cout<<"i " <<i<<" j "<<j<<" a[i] "<< a[i]<< " a[j] "<<a[j]<<"\n"; 
			count++;
		}
return count;
}
void x()
{
 int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  //vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, 0, a.size()-1) << '\n';
}
int test() {
	fo(i,10000)
	{
		if(i%100==0)
			cout<<"done "<<i<<"%\n";
		srand(time(NULL));
		vector<int >a;
		int n=rand()%100000+1;
		fo(i,n)
		p_b(a,rand()%1000000000+1);
		//assert(get_number_of_inversions(a, 0, a.size())==naive(a));

		//vector<int > a={2 ,3 ,9 ,2 ,9};
		int b=naive(a);
		int c=get_number_of_inversions(a, 0, a.size()-1);
		assert(b==c);
	}
}
int main()
{
x();
	//test();
}
