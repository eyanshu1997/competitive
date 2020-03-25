#include<bits/stdc++.h>
using namespace std;
int cmp(const void *ap,const void *bp)
{
	const int *a=(int *)ap;
	const int *b=(int *)bp;
	if(*a<*b)
		return -1;
	if(*a>*b)
		return 1;
	if(*a==*b)
		return 0;
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int arr_size=sizeof(arr)/sizeof(arr[0]);
	int key=4;
	int *res=(int *)bsearch(&key,arr,arr_size,sizeof(arr[0]),cmp);
	if(*res==-1)
		cout<<"not found\n";
	else
		cout<<"found at index "<<*res<<"\n";
	return 0;
}
